#ifndef HealthDto_hpp
#define HealthDto_hpp

#include "oatpp/core/data/mapping/type/Object.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  Data Transfer Object. Object containing fields only.
 *  Used in API for serialization/deserialization and validation
 */
class HealthDto : public oatpp::Object {
  
  DTO_INIT(HealthDto, Object)
  
  DTO_FIELD(String, status);
  
};

#include OATPP_CODEGEN_END(DTO)

#endif /* HealthDto_hpp */
