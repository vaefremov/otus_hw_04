#include "output_ip.h"

#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>
#include <string>
#include <tuple>

using namespace OTUS;

TEST(Utilities, tuple_int)
{
    std::tuple<int, int, int, int> in{1, 2, 3, 4};
    std::ostringstream str;

    print_ip(in, str);

    std::string exp{"1.2.3.4"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}

// Check if print_ip works for tuples longer than 4 elements
TEST(Utilities, tuple_int_more_than_4)
{
    auto in = std::make_tuple(1, 2, 3, 4, 5);
    std::ostringstream str;

    print_ip(in, str);

    std::string exp{"1.2.3.4.5"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}

// Check if print_ip works for tuples of type differing from ints
TEST(Utilities, tuple_char)
{
    auto in = std::make_tuple("1", "2");
    std::ostringstream str;

    print_ip(in, str);

    std::string exp{"1.2"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}

// Check if print_ip works for tuples with just one element
TEST(Utilities, tuple_1int)
{
    auto in = std::make_tuple(42);
    std::ostringstream str;

    print_ip(in, str);

    std::string exp{"42"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}

// The following test won't compile because the 4th element
// is not convertible to int
//
// TEST(Utilities, tuple_diff)
// {
//     std::tuple<int, int, int, std::string> in{1, 2, 3, "4"};
//     std::ostringstream str;

//     print_ip(in, str, false);

//     std::string exp{"1.2.3.4"};
//     std::string res = str.str();
//     std::cout << "DEBUG" << res << std::endl;
//     ASSERT_EQ(exp, res);
// }

