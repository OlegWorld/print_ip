#pragma once

#include <iostream>
#include <string>
#include <type_traits>
#include <vector>
#include <list>
#include <tuple>

template <typename T>
struct is_vector : std::false_type {};

template <typename U, typename Alloc>
struct is_vector<std::vector<U, Alloc>> : std::true_type {};

template <typename T>
struct is_list : std::false_type {};

template <typename U, typename Alloc>
struct is_list<std::list<U, Alloc>> : std::true_type {};

template <typename T>
struct is_tuple : std::false_type {};

template <typename... Args>
struct is_tuple<std::tuple<Args...>> : std::true_type {};

template <typename T>
std::enable_if_t<std::is_same<T, std::string>::value> print_ip(const T& ip) {
    std::cout << ip;
}

template <typename T>
std::enable_if_t<std::is_integral<T>::value> print_ip(const T& ip) {
    for (size_t i = sizeof(T); i != 0 ; i--) {
        std::cout   << ((ip >> 8 * (i - 1)) & 0xff)
                    << (i != 1 ? "." : "");
    }
}

template <typename T>
std::enable_if_t<is_vector<T>::value || is_list<T>::value> print_ip(const T& ip) {
    for (const auto& el : ip) {
        print_ip(el);
        std::cout <<  (&el != &ip.back() ? "." : "");
    }
}

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

template<typename... Args>
struct iterate_tuple<0, Args...>
{
    static void print(const std::tuple<Args...>& t)
    {
        print_ip(std::get<0>(t));
    }
};

template <typename... Args>
void print_tuple(const std::tuple<Args...>& t) {
    constexpr int tuple_size = std::tuple_size<std::tuple<Args...>>::value;

    iterate_tuple<tuple_size - 1, Args...>::print(t);
}

template <typename T>
std::enable_if_t<is_tuple<T>::value> print_ip(const T& ip) {
    print_tuple(ip);
}

