#pragma once

#include <iostream>
#include <cstddef>

template <typename Int_T>
void print_integer(Int_T number) {
    for (size_t i = sizeof(Int_T); i != 0 ; i--) {
        std::cout   << ((number >> 8 * (i - 1)) & 0xff)
                    << (i != 1 ? "." : "");
    }
    std::cout << std::endl;
}
