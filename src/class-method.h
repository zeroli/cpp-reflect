#pragma once

#include <string>

namespace reflect {
class ClassMethod {
public:
    ClassMethod() = default;
    ClassMethod(const std::string& name)
        : name_(name)
    {}

    const std::string& name() const { return name_; }
private:
    std::string name_;
};
}  // namespace reflect
