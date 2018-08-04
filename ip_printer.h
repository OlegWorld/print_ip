#pragma once

#include <iostream>
#include <string>
#include <tuple>
#include <type_traits>

template <typename T>
std::enable_if_t<std::is_same<T, std::string>::value> print_ip(const T& ip) {
    std::cout << ip << std::endl;
}

template <typename T>
std::enable_if_t<std::is_integral<T>::value> print_ip(const T& ip) {
    for (size_t i = sizeof(T); i != 0 ; i--) {
        std::cout   << ((ip >> 8 * (i - 1)) & 0xff)
                    << (i != 1 ? "." : "");
    }
    std::cout << std::endl;
}

//template <template <typename, typename> typename Cont, typename T, typename Alloc>
//void print_ip(const Cont<T, Alloc>& ip) {
//    for (const auto& el : ip) {
//        std::cout << int(el) << (&el != &ip.back() ? "." : "");
//    }
//    std::cout << std::endl;
//}

template <typename T>
std::enable_if_t<!(std::is_same<T, std::string>::value) &&
                 !(std::is_integral<T>::value)>
                 print_ip(const T& ip) {
    for (const auto& el : ip) {
        std::cout << int(el) << (&el != &ip.back() ? "." : "");
    }
    std::cout << std::endl;
}

//template <typename... Args>
//void print_ip(const std::tuple<Args...>& ip) {
//
//}
