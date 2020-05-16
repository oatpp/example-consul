
#ifndef DemoController_hpp
#define DemoController_hpp

#include "oatpp-consul/Client.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<-- Begin codegen

/**
 *  EXAMPLE ApiController
 *  Basic examples of howto create ENDPOINTs
 *  More details on oatpp.io
 */
class DemoController : public oatpp::web::server::api::ApiController {
protected:
  DemoController(const std::shared_ptr<ObjectMapper>& objectMapper)
    : oatpp::web::server::api::ApiController(objectMapper)
  {}
private:
  
  /**
   *  Inject Database component
   */
  OATPP_COMPONENT(std::shared_ptr<oatpp::consul::Client>, m_consulClient);
public:
  
  /**
   *  Inject @objectMapper component here as default parameter
   *  Do not return bare Controllable* object! use shared_ptr!
   */
  static std::shared_ptr<DemoController> createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>,
                                                                 objectMapper)){
    return std::shared_ptr<DemoController>(new DemoController(objectMapper));
  }
  
  /**
   *  Insert Your endpoints here !!!
   */
  
  ENDPOINT("PUT", "demo/consul/kv/{key}", storeValue,
           PATH(String, key),
           BODY_STRING(String, value)) {
    m_consulClient->kvPut(key, value);
    return createResponse(Status::CODE_200, "value stored");
  }
  
  ENDPOINT("GET", "demo/consul/kv/{key}", getValue,
           PATH(String, key)) {
    return createResponse(Status::CODE_200, m_consulClient->kvGet(key));
  }
  
};

#include OATPP_CODEGEN_END(ApiController) //<-- End codegen

#endif /* DemoController_hpp */
