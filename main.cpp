#include <iostream>
#include "ip_printer.h"

int main() {
    print_integer(char(-1));
    print_integer(short(0));
    print_integer(int(2130706433));
    print_integer(long(8875824491850138409));
    return 0;
}