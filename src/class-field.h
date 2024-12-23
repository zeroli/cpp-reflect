#pragma once

#include <string>

namespace reflect {
class ClassField {
public:
    ClassField() = default;
    ClassField(const std::string& name, const std::string& type, size_t offset)
        : name_(name), type_(type), offset_(offset)
    {}

    const std::string& name() const { return name_; }
    const std::string& type() const { return type_; }
    size_t offset() const { return offset_; }
private:
    std::string name_;
    std::string type_;
    size_t offset_;
};
}  // namespace reflect
