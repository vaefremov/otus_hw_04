#pragma once

#include <ostream>
#include <iomanip>

namespace OTUS
{


namespace detail
{
    using std::begin;
    using std::end;
 
    template <typename T>
    auto is_iterable_impl(int)
    -> decltype (
        begin(std::declval<T&>()) != end(std::declval<T&>()), // begin/end and operator !=
        ++std::declval<decltype(begin(std::declval<T&>()))&>(), // operator ++
        *begin(std::declval<T&>()), // operator*
        std::true_type{});
 
    template <typename T>
    std::false_type is_iterable_impl(...);
 
}
 
template <typename T>
using is_iterable = decltype(detail::is_iterable_impl<T>(0));


template<typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
print_ip(T ip, std::ostream& out, bool add_endline = true)
{
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
typename std::enable_if<is_iterable<T>::value, void>::type
print_ip(T const& ip, std::ostream& out, bool add_endline = true)
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
    if(add_endline)
        out << std::endl;
}

template<>
void print_ip<std::string>(std::string const& ip, std::ostream& out, bool add_endline)
{
    out <<  ip;
    if(add_endline)
        out << std::endl;
}

inline void print_ip(std::tuple<int, int, int, int> const& ip, std::ostream& out, bool add_endline = true)
{
    out << std::get<0>(ip) << "." << std::get<1>(ip) << "." << std::get<2>(ip) << "." << std::get<3>(ip);
    if(add_endline)
        out << std::endl;
}


}