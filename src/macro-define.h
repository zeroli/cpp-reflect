#pragma once

#define CAT_HELPER(x, y) x ## y
#define CAT(x, y) CAT_HELPER(x, y)
#define UNUSED_VAR(var) CAT(var, __COUNTER__) __attribute__((unused))

#define OFFSET(T, FIELD) (size_t)(&(((T*)0)->FIELD))
