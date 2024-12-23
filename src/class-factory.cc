#include "class-factory.h"

#include "object.h"

namespace reflect {
void ClassFactory::register_class(const std::string& className, ClassObjCreator_t creator)
{
    class_creator_map_[className] = std::move(creator);
}

Object* ClassFactory::create_class(const std::string& className)
{
    if (class_creator_map_.count(className) == 0) {
        return nullptr;
    }
    return class_creator_map_.at(className)();
}

void ClassFactory::register_class_field(
                        const std::string& className,
                        const std::string& fieldName,
                        const std::string& fieldType,
                        size_t fieldOffset)
{
    class_field_map_[className].emplace_back(
        fieldName, fieldType, fieldOffset
    );
}

int ClassFactory::get_field_count(const std::string& className)
{
    return (int)class_field_map_[className].size();
}

ClassField* ClassFactory::get_field(const std::string& className, const std::string& fieldName)
{
    for (auto&& field : class_field_map_[className]) {
        if (field.name() == fieldName) {
            return &field;
        }
    }
    return nullptr;
}

ClassField* ClassFactory::get_field(const std::string& className, int idx)
{
    if (idx < 0 || idx >= get_field_count(className)) {
        return nullptr;
    }
    return &class_field_map_[className][idx];
}

}  // namespace reflect
