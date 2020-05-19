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

// Printing tuples is another stuff! Requires variadic templates and recursion.

// Smart method to check if all boolean values in a sequence are true, 
// found here: https://www.fluentcpp.com/2019/01/25/variadic-number-function-parameters-type/
template<bool...> struct bool_pack{};
template<typename... Ts>
using conjunction = std::is_same<bool_pack<true,Ts::value...>, bool_pack<Ts::value..., true>>;

template<typename... Ts>
using AllInts = typename std::enable_if<conjunction<std::is_convertible<Ts, int>...>::value>::type;

template<typename Tuple, std::size_t N>
struct TuplePrinter {
    static void print(const Tuple& t, std::ostream& out) 
    {
        TuplePrinter<Tuple, N-1>::print(t, out);
        out << "." << std::get<N-1>(t);
    }
};
 
template<typename Tuple>
struct TuplePrinter<Tuple, 1> {
    static void print(const Tuple& t, std::ostream& out) 
    {
        out << std::get<0>(t);
    }
};

template<typename... Args, typename = AllInts<Args...>>
void print_ip(const std::tuple<Args...>& t, std::ostream& out)
{
    TuplePrinter<decltype(t), sizeof...(Args)>::print(t, out);
}

template<typename T>
void print_ip_with_endline(T ip, std::ostream& out)
{
    print_ip(ip, out);
    out << std::endl;
}

}