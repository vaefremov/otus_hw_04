#include "output_ip.h"

#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace OTUS;

TEST(Utilities, integral_int)
{
    int in{1234};
    std::ostringstream str;
    print_ip(in, str, false);
    std::string exp{"0.0.4.210"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}

TEST(Utilities, integral_int2)
{
    int in{2130706433};
    std::ostringstream str;
    print_ip(in, str, false);
    std::string exp{"127.0.0.1"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}

TEST(Utilities, integral_char)
{
    char in{-1};
    std::ostringstream str;
    print_ip(in, str, false);
    std::string exp{"255"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}

TEST(Utilities, integral_short)
{
    short in{0};
    std::ostringstream str;
    print_ip(in, str, false);
    std::string exp{"0.0"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}

TEST(Utilities, integral_long)
{
    long in{8875824491850138409};
    std::ostringstream str;
    print_ip(in, str, false);
    std::string exp{"123.45.67.89.101.112.131.41"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}
