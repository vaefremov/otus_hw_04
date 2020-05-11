#include "output_ip.h"

#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>
#include <string>

using namespace OTUS;

TEST(Utilities, vector_int)
{
    std::vector<int> in{1, 2, 3, 4, 5, 6};
    std::ostringstream str;

    print_ip(in, str, false);

    std::string exp{"1.2.3.4.5.6"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}

TEST(Utilities, list_int)
{
    std::list<int> in{1, 2, 3, 4, 5, 6};
    std::ostringstream str;

    print_ip(in, str, false);

    std::string exp{"1.2.3.4.5.6"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}
