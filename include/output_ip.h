#pragma once

#include <ostream>
#include <iomanip>
#include <vector>
#include <list>

namespace OTUS
{

template<typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
print_ip(T ip, std::ostream& out)
{
    char* ip_bytes = reinterpret_cast<char*>(&ip);
    for (size_t i = 0; i < sizeof(ip); i++)
    {
        if(i)
            out << ".";
        out << (0xFF & ip_bytes[sizeof(ip) - i -1]) ;
    }
}

template<typename T>
typename std::enable_if<std::is_same<typename std::vector<typename T::value_type>, T>::value || 
                        std::is_same<typename std::list<typename T::value_type>, T>::value, 
                                            void>::type
print_ip(T const& ip, std::ostream& out)
{
    bool starting{true};
    for(auto const & v: ip)
    {
        if(!starting)
            out << ".";
        else
            starting = false;        
        out << v;
    }
}

template<typename T>
std::enable_if_t<std::is_same<T, std::basic_string<typename T::value_type>>::value, void>
print_ip(T ip, std::ostream& out)
{
    out <<  ip;
}

template<typename T>
void print_ip(std::tuple<T, T, T, T> const& ip, std::ostream& out)
{
    out << std::get<0>(ip) << "." << std::get<1>(ip) << "." << std::get<2>(ip) << "." << std::get<3>(ip);
}

template<typename T>
void print_ip_with_endline(T ip, std::ostream& out)
{
    print_ip(ip, out);
    out << std::endl;
}

}