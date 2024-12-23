#pragma once

#include "class-factory.h"
#include "macro-define.h"

namespace reflect {

class ClassRegister {
public:
    ClassRegister(const std::string& className, ClassObjCreator_t obj_creator)
    {
        auto* factory = ClassFactory::instance();
        factory->register_class(className, std::move(obj_creator));
    }
    ClassRegister(const std::string& className, const std::string& fieldName,
                 const std::string& fieldType, size_t fieldOffset)
    {
        auto* factory = ClassFactory::instance();
        factory->register_class_field(className, fieldName, fieldType, fieldOffset);
    }
};

#define REGISTER_CLASS(CLASS) \
    static ClassRegister UNUSED_VAR(regclass)(#CLASS, [] { \
        Object* p = new CLASS(); \
        p->set_class_name(#CLASS); \
        return p; \
    })\
///###

#define REGISTER_CLASS_FIELD(CLASS, FIELD_NAME, FIELD_TYPE) \
    static ClassRegister UNUSED_VAR(regclass)(#CLASS,\
        #FIELD_NAME, #FIELD_TYPE, OFFSET(CLASS, FIELD_NAME) \
    )\
///###

}  // namespace reflect
