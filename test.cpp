#include <iostream>
#include <sstream>
#include <gtest/gtest.h>
#include "ip_printer.h"

TEST(printing, char_printing) {
    std::ostringstream os;
    auto oldbuf = std::cout.rdbuf();
    std::cout.rdbuf(os.rdbuf());

    print_integer(char(1));

    EXPECT_EQ(os.str(), "1\n");

    std::cout.rdbuf(oldbuf);
}

TEST(printing, short_printing) {
    std::ostringstream os;
    auto oldbuf = std::cout.rdbuf();
    std::cout.rdbuf(os.rdbuf());

    print_integer(short(2018));

    EXPECT_EQ(os.str(), "7.226\n");

    std::cout.rdbuf(oldbuf);
}

TEST(printing, int_printing) {
    std::ostringstream os;
    auto oldbuf = std::cout.rdbuf();
    std::cout.rdbuf(os.rdbuf());

    print_integer(int(0xaaaaaaaa));

    EXPECT_EQ(os.str(), "170.170.170.170\n");

    std::cout.rdbuf(oldbuf);
}

TEST(printing, long_printing) {
    std::ostringstream os;
    auto oldbuf = std::cout.rdbuf();
    std::cout.rdbuf(os.rdbuf());

    print_integer(long(0x123456789abcdef));

    EXPECT_EQ(os.str(), "1.35.69.103.137.171.205.239\n");

    std::cout.rdbuf(oldbuf);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}