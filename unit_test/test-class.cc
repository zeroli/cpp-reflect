#include "test-class.h"

#include "class-register.h"

namespace reflect {
REGISTER_CLASS(A);
REGISTER_CLASS_FIELD(A, int_, int);
REGISTER_CLASS_FIELD(A, double_, double);
REGISTER_CLASS_FIELD(A, str_, std::string);
REGISTER_CLASS_FIELD(A, vec_, std::vector<int>);
}  // namespace reflect
