#include <iostream>
#include "ip_printer.h"

int main() {
    print_ip(char(-1));
    std::cout << std::endl;

    print_ip(short(0));
    std::cout << std::endl;

    print_ip(int(2130706433));
    std::cout << std::endl;

    print_ip(long(8875824491850138409));
    std::cout << std::endl;

    print_ip("192.168.0.1");
    std::cout << std::endl;

    print_ip(std::string("192.168.0.2"));
    std::cout << std::endl;

    print_ip(std::vector<uint8_t>{1, 2, 3, 4});
    std::cout << std::endl;

    print_ip(std::list<uint16_t>{1, 2, 3, 4});
    std::cout << std::endl;

    print_ip(std::tuple<uint8_t, uint16_t, uint32_t, uint64_t>(1, 2, 3, 4));
    std::cout << std::endl;

    return 0;
}