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

    print_ip(in, str, false);

    std::string exp{"1.2.3.4"};
    std::string res = str.str();
    std::cout << "DEBUG" << res << std::endl;
    ASSERT_EQ(exp, res);

}
// The following test doesn't compile!
//
// TEST(Utilities, tuple_diff)
// {
//     std::tuple<int, int, int, long> in{1, 2, 3, 4};
//     std::ostringstream str;

//     print_ip(in, str, false);

//     std::string exp{"1.2.3.4"};
//     std::string res = str.str();
//     std::cout << "DEBUG" << res << std::endl;
//     ASSERT_EQ(exp, res);
// }