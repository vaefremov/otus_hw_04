/*! \file
\brief The main file of the print_ip program,

The print_ip program takes no CLI parameters. When run, it outputs
a number of lines corresponding to output of (fictitious) IP addresses,
as required by the OTUS homework assignment 04.

The supposed output is as follows:

    255
    0.0
    127.0.0.1
    123.45.67.89.101.112.131.41
    trololo
    1.2.3.4.5.6
    42.21.0
    0.1.2.3
*/

#include "output_ip.h"

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <list>

int main()
{
    char ip_char{-1};
    short ip_short{0};
    int ip_int{2130706433};
    long ip_long{8875824491850138409};
    std::string ip_string{"trololo"};
    std::vector<int> ip_vector{1, 2, 3, 4, 5, 6};
    std::list<int> ip_list{42, 21, 0};
    std::tuple<int, int, int, int> ip_tuple = std::make_tuple(0, 1, 2, 3);
    std::tuple<int, int, int, long> ip_tuple_wrong = std::make_tuple(0, 1, 2, 3);

    OTUS::print_ip_with_endline(ip_char, std::cout);
    OTUS::print_ip_with_endline(ip_short, std::cout);
    OTUS::print_ip_with_endline(ip_int, std::cout);
    OTUS::print_ip_with_endline(ip_long, std::cout);
    OTUS::print_ip_with_endline(ip_string, std::cout);
    OTUS::print_ip_with_endline(ip_vector, std::cout);
    OTUS::print_ip_with_endline(ip_list, std::cout);
    OTUS::print_ip_with_endline(ip_tuple, std::cout);
    // The following line is not compilable (tuple must have coinciding types of all elements):
    // OTUS::print_ip(ip_tuple_wrong, std::cout);

}