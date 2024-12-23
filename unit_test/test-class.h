#pragma once

#include "object.h"

#include <string>
#include <vector>

class A : public reflect::Object {
public:
    A() = default;
    ~A() = default;

public:
    int int_;
    double double_;
    std::string str_;
    std::vector<int> vec_;
};
