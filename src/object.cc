#include "object.h"

#include "class-factory.h"

namespace reflect {
int Object::get_field_count() const
{
    auto* factory = ClassFactory::instance();
    return factory->get_field_count(name_);
}

ClassField* Object::get_field(const std::string& fieldName)
{
    auto* factory = ClassFactory::instance();
    return factory->get_field(name_, fieldName);
}

ClassField* Object::get_field(int idx)
{
    auto* factory = ClassFactory::instance();
    return factory->get_field(name_, idx);
}
}  // namespace reflect
