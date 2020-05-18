#include "output_ip.h"

#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace OTUS;

TEST(Utilities, string)
{
    std::string in{"trololo"};
    std::ostringstream str;
    print_ip(in, str);
    std::string exp{"trololo"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}

TEST(Utilities, string_with_endline)
{
    std::string in{"trololo"};
    std::ostringstream str;
    std::ostringstream str_exp;
    str_exp << in << std::endl;
    print_ip_with_endline(in, str);
    std::string exp = str_exp.str();
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}

