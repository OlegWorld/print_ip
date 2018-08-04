#pragma once

#include <iostream>
#include <string>
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



