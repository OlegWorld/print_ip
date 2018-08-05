#pragma once

#include <iostream>
#include <string>
#include <type_traits>
#include <vector>
#include <list>
#include <tuple>

template <typename T>
struct is_vector : std::false_type {};

/// \brief test if template parameter is std::vector
template <typename U, typename Alloc>
struct is_vector<std::vector<U, Alloc>> : std::true_type {};

template <typename T>
struct is_list : std::false_type {};

/// \brief test if template parameter is std::list
template <typename U, typename Alloc>
struct is_list<std::list<U, Alloc>> : std::true_type {};

template <typename T>
struct is_tuple : std::false_type {};

/// \brief test if template parameter is std::tuple
template <typename... Args>
struct is_tuple<std::tuple<Args...>> : std::true_type {};

template <typename T>
struct is_cstring : std::false_type {};

template <>
struct is_cstring<char[]> : std::true_type {};

/// \brief test if template parameter is c-style string
template <size_t N>
struct is_cstring<char[N]> : std::true_type {};

/// \brief print_ip function for c-style strings and std::string
template <typename T>
std::enable_if_t<std::is_same<T, std::string>::value ||
                 is_cstring<T>::value> print_ip(const T& ip) {
    std::cout << ip;
}

/// \brief print_ip function for integral types
template <typename T>
std::enable_if_t<std::is_integral<T>::value> print_ip(const T& ip) {
    for (size_t i = sizeof(T); i != 0 ; i--) {
        std::cout   << ((ip >> 8 * (i - 1)) & 0xff)
                    << (i != 1 ? "." : "");
    }
}

/// \brief print_ip function for std::vector and std::list
template <typename T>
std::enable_if_t<is_vector<T>::value || is_list<T>::value> print_ip(const T& ip) {
    for (const auto& el : ip) {
        print_ip(el);
        std::cout <<  (&el != &ip.back() ? "." : "");
    }
}

/// \brief helper function for iterating through std::tuple
template<int index, typename... Args>
struct iterate_tuple
{
    static void print(const std::tuple<Args...>& t)
    {
        iterate_tuple<index - 1, Args...>::print(t);

        std::cout << ".";
        print_ip(std::get<index>(t));
    }
};

/// \brief helper function for final std::tuple element
template<typename... Args>
struct iterate_tuple<0, Args...>
{
    static void print(const std::tuple<Args...>& t)
    {
        print_ip(std::get<0>(t));
    }
};

/// \brief helper function for printing std::tuple
template <typename... Args>
void print_tuple(const std::tuple<Args...>& t) {
    constexpr int tuple_size = std::tuple_size<std::tuple<Args...>>::value;

    iterate_tuple<tuple_size - 1, Args...>::print(t);
}

/// \brief print_ip function for std::tuple
template <typename T>
std::enable_if_t<is_tuple<T>::value> print_ip(const T& ip) {
    print_tuple(ip);
}

