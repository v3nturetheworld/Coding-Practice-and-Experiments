#include <gtest/gtest.h>
#include "hello-world.h"
#include <iostream>


TEST(TestMessages, Test_1)
{
    HelloWorldClass h;
    std::string s("Hello World!!!");
    h.set_message(s);
    EXPECT_EQ(s, h.get_message());
}

TEST(TestNumber, Test_1)
{
    HelloWorldClass h;
    const int n = 42;
    h.set_number(n);

    EXPECT_EQ(42, h.get_number());
}

