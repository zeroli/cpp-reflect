#include <gtest/gtest.h>

#include "class-register.h"
#include "test-class.h"

using namespace reflect;

TEST(reflect, test_class_register)
{
    {
        auto a_obj = std::unique_ptr<Object>(ClassFactory::instance()->create_class("A"));
        ASSERT_TRUE(a_obj != nullptr);
        {
            a_obj->set("int_", 3);
            int val = -1;
            EXPECT_TRUE(a_obj->get("int_", val));
            EXPECT_EQ(3, val);
        }
        {
            a_obj->set("double_", 2.3);
            double val = 0.;
            EXPECT_TRUE(a_obj->get("double_", val));
            EXPECT_FLOAT_EQ(2.3, val);
        }
        {
            a_obj->set("str_", std::string("hello"));
            std::string val;
            EXPECT_TRUE(a_obj->get("str_", val));
            EXPECT_EQ("hello", val);
        }
        {
            std::vector<int> v{1,2,3};
            a_obj->set("vec_", v);
            std::vector<int> val;
            EXPECT_TRUE(a_obj->get("vec_", val));
            EXPECT_EQ(v, val);
        }
    }
}
