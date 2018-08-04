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

    EXPECT_EQ(os.str(), "1\n");

    std::cout.rdbuf(oldbuf);
}

TEST(printing, short_printing) {
    std::ostringstream os;
    auto oldbuf = std::cout.rdbuf();
    std::cout.rdbuf(os.rdbuf());

    print_ip(short(2018));

    EXPECT_EQ(os.str(), "7.226\n");

    std::cout.rdbuf(oldbuf);
}

TEST(printing, int_printing) {
    std::ostringstream os;
    auto oldbuf = std::cout.rdbuf();
    std::cout.rdbuf(os.rdbuf());

    print_ip(int(0xaaaaaaaa));

    EXPECT_EQ(os.str(), "170.170.170.170\n");

    std::cout.rdbuf(oldbuf);
}

TEST(printing, long_printing) {
    std::ostringstream os;
    auto oldbuf = std::cout.rdbuf();
    std::cout.rdbuf(os.rdbuf());

    print_ip(long(0x123456789abcdef));

    EXPECT_EQ(os.str(), "1.35.69.103.137.171.205.239\n");

    std::cout.rdbuf(oldbuf);
}

TEST(printing, string_printing) {
    std::ostringstream os;
    auto oldbuf = std::cout.rdbuf();
    std::cout.rdbuf(os.rdbuf());

    print_ip(std::string("127.0.0.1"));

    EXPECT_EQ(os.str(), "127.0.0.1\n");

    std::cout.rdbuf(oldbuf);
}

TEST(printing, vector_printing) {
    std::ostringstream os;
    auto oldbuf = std::cout.rdbuf();
    std::cout.rdbuf(os.rdbuf());

    print_ip(std::vector<unsigned char>{192, 168, 0, 1});

    EXPECT_EQ(os.str(), "192.168.0.1\n");

    std::cout.rdbuf(oldbuf);
}

TEST(printing, list_printing) {
    std::ostringstream os;
    auto oldbuf = std::cout.rdbuf();
    std::cout.rdbuf(os.rdbuf());

    print_ip(std::list<unsigned char>{192, 168, 0, 1});

    EXPECT_EQ(os.str(), "192.168.0.1\n");

    std::cout.rdbuf(oldbuf);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}