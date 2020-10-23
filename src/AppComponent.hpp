
#ifndef AppComponent_hpp
#define AppComponent_hpp

#include "oatpp-consul/Client.hpp"

#include "oatpp/web/client/HttpRequestExecutor.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/web/server/HttpRouter.hpp"
#include "oatpp/network/tcp/client/ConnectionProvider.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"

#include "oatpp/parser/json/mapping/Serializer.hpp"
#include "oatpp/parser/json/mapping/Deserializer.hpp"

#include "oatpp/core/macro/component.hpp"

/**
 *  Class which creates and holds Application components and registers components in oatpp::base::Environment
 *  Order of components initialization is from top to bottom
 */
class AppComponent {
public:
  
  /**
   *  Create ConnectionProvider component which listens on the port
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, serverConnectionProvider)([] {
    return oatpp::network::tcp::server::ConnectionProvider::createShared({"0.0.0.0", 8000, oatpp::network::Address::IP_4});
  }());
  
  /**
   *  Create Router component
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, httpRouter)([] {
    return oatpp::web::server::HttpRouter::createShared();
  }());
  
  /**
   *  Create ConnectionHandler component which uses Router component to route requests
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, serverConnectionHandler)([] {
    OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router); // get Router component
    return oatpp::web::server::HttpConnectionHandler::createShared(router);
  }());
  
  /**
   *  Create ObjectMapper component to serialize/deserialize DTOs in Contoller's API
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, apiObjectMapper)([] {
    
    auto serializerConfig = oatpp::parser::json::mapping::Serializer::Config::createShared();
    serializerConfig->includeNullFields = true;
    
    auto deserializerConfig = oatpp::parser::json::mapping::Deserializer::Config::createShared();
    deserializerConfig->allowUnknownFields = false;
    
    auto objectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared(serializerConfig, deserializerConfig);
    return objectMapper;
    
  }());
  
  /**
   *  Create Demo-oatpp::consul::Client component
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::consul::Client>, consulClient)([] {

    OATPP_LOGI("AppComponent", "Assuming Consul is on port 8500");

    // Create connection provider for Consul
    // In case you need secure connection provider so you can connect to Consul via https see oatpp-libressl and tls-libressl example project
    auto connectionProvider = oatpp::network::tcp::client::ConnectionProvider::createShared({"localhost", 8500});
    
    // Create httpRequestExecutor
    auto requestExecutor = oatpp::web::client::HttpRequestExecutor::createShared(connectionProvider);
    
    // Create and return consul client
    return oatpp::consul::Client::createShared(requestExecutor);
  }());

};

#endif /* AppComponent_hpp */
