#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <gtest/gtest.h>
#include "ip_printer.h"

TEST(printing, char_printing) {
    std::ostringstream os;
    auto oldbuf = std::cout.rdbuf();
    std::cout.rdbuf(os.rdbuf());

    print_ip(char(1));

    EXPECT_EQ(os.str(), "1");

    std::cout.rdbuf(oldbuf);
}

TEST(printing, short_printing) {
    std::ostringstream os;
    auto oldbuf = std::cout.rdbuf();
    std::cout.rdbuf(os.rdbuf());

    print_ip(short(2018));

    EXPECT_EQ(os.str(), "7.226");

    std::cout.rdbuf(oldbuf);
}

TEST(printing, int_printing) {
    std::ostringstream os;
    auto oldbuf = std::cout.rdbuf();
    std::cout.rdbuf(os.rdbuf());

    print_ip(int(0xaaaaaaaa));

    EXPECT_EQ(os.str(), "170.170.170.170");

    std::cout.rdbuf(oldbuf);
}

TEST(printing, long_printing) {
    std::ostringstream os;
    auto oldbuf = std::cout.rdbuf();
    std::cout.rdbuf(os.rdbuf());

    print_ip(long(0x123456789abcdef));

    EXPECT_EQ(os.str(), "1.35.69.103.137.171.205.239");

    std::cout.rdbuf(oldbuf);
}

TEST(printing, string_printing) {
    std::ostringstream os;
    auto oldbuf = std::cout.rdbuf();
    std::cout.rdbuf(os.rdbuf());

    print_ip(std::string("127.0.0.1"));

    EXPECT_EQ(os.str(), "127.0.0.1");

    std::cout.rdbuf(oldbuf);
}

TEST(printing, cstring_printing) {
    std::ostringstream os;
    auto oldbuf = std::cout.rdbuf();
    std::cout.rdbuf(os.rdbuf());

    print_ip("127.0.0.1");

    EXPECT_EQ(os.str(), "127.0.0.1");

    std::cout.rdbuf(oldbuf);
}

TEST(printing, list_printing) {
    std::ostringstream os;
    auto oldbuf = std::cout.rdbuf();
    std::cout.rdbuf(os.rdbuf());

    print_ip(std::list<unsigned char>{192, 168, 0, 1});

    EXPECT_EQ(os.str(), "192.168.0.1");

    std::cout.rdbuf(oldbuf);
}

TEST(printing, vector_printing) {
    std::ostringstream os;
    auto oldbuf = std::cout.rdbuf();
    std::cout.rdbuf(os.rdbuf());

    print_ip(std::vector<short>{192, 168, 0, 1});

    EXPECT_EQ(os.str(), "0.192.0.168.0.0.0.1");

    std::cout.rdbuf(oldbuf);
}

TEST(printing, tuple_printing) {
    std::ostringstream os;
    auto oldbuf = std::cout.rdbuf();
    std::cout.rdbuf(os.rdbuf());

    print_ip(std::tuple<uint8_t, uint32_t, uint8_t> {1, 2, 3});

    EXPECT_EQ(os.str(), "1.0.0.0.2.3");

    std::cout.rdbuf(oldbuf);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}