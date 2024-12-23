#pragma once

#include "class-method.h"
#include "class-field.h"

#include <string>
#include <cassert>

namespace reflect {
class ClassField;
class ClassMethod;

class Object {
public:
    virtual ~Object() = default;

    void set_class_name(const std::string& name) { name_ = name; }
    const std::string& get_class_name() const { return name_; }

    /// field set/get
    int get_field_count() const;
    ClassField* get_field(const std::string& fieldName);
    ClassField* get_field(int idx);

    template <typename T>
    void set(const std::string& fieldName, const T& value) {
        auto* field = get_field(fieldName);
        assert(field && "Field doesn't exist");
        auto offset = field->offset();
        *reinterpret_cast<T*>((uintptr_t)this + offset) = value;
    }
    template <typename T>
    bool get(const std::string& fieldName, T& value) {
        auto* field = get_field(fieldName);
        assert(field && "Field doesn't exist");
        auto offset = field->offset();
        value = *reinterpret_cast<T*>((uintptr_t)this + offset);
        return true;
    }
private:
    std::string name_;
};
}  // namespace reflect
