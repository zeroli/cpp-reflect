#pragma once

#include "singleton.h"
#include "class-field.h"
#include "class-method.h"
#include "object.h"

#include <string>
#include <memory>
#include <vector>
#include <map>
#include <functional>

namespace reflect {
class Object;
class ClassField;
class ClassMethod;

using ClassObjCreator_t = std::function<Object* ()>;

class ClassFactory : public Singleton<ClassFactory>
{
public:
    // class registration
    void register_class(const std::string& className, ClassObjCreator_t creator);
    Object* create_class(const std::string& className);

    // class method registration
    void register_class_field(
            const std::string& className,
            const std::string& fieldName,
            const std::string& fieldType,
            size_t fieldOffset);
    int get_field_count(const std::string& className);
    ClassField* get_field(const std::string& className, const std::string& fieldName);
    ClassField* get_field(const std::string& className, int idx);

private:
    friend class Singleton<ClassFactory>;
    ClassFactory() = default;
    ~ClassFactory() = default;
private:
    std::map<std::string, ClassObjCreator_t> class_creator_map_;
    std::map<std::string, std::vector<ClassField>> class_field_map_;
    std::map<std::string, std::vector<ClassMethod>> class_method_map_;
};

}  // namespace reflect
