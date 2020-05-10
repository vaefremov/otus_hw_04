#pragma once

#include <ostream>
#include <iomanip>

namespace OTUS
{

template<typename T>
std::enable_if_t<std::is_integral_v<T>, void>
print_ip(T ip, std::ostream& out, bool add_endline = true)
{
    // out << __PRETTY_FUNCTION__ << " " << sizeof(ip) << " " << ip;
    char* ip_bytes = reinterpret_cast<char*>(&ip);
    for (size_t i = 0; i < sizeof(ip); i++)
    {
        if(i)
            out << ".";
        out << (0xFF & ip_bytes[sizeof(ip) - i -1]) ;
    }
    if(add_endline)
        out << std::endl;
}

template<typename T>
std::enable_if_t<std::is_same_v<T, std::string>, void>
print_ip(T ip, std::ostream& out, bool add_endline = true)
{
    out <<  ip;
    if(add_endline)
        out << std::endl;
}

}