cmake_minimum_required(VERSION 3.5)
project(print_ip)

find_package(GTest REQUIRED)
find_package (Threads REQUIRED)

add_executable(${PROJECT_NAME} main.cpp ip_printer.h)
add_executable(printer_test ip_printer.h test.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${GTEST_INCLUDE_DIRS})

set_target_properties(${PROJECT_NAME} PROPERTIES    CXX_STANDARD 14
                                                    CXX_STANDARD_REQUIRED ON
                                                    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra;-Werror")

target_link_libraries(printer_test ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

enable_testing()

add_test(test printer_test)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "1")
set(CPACK_PACKAGE_VERSION_PATCH "$ENV{TRAVIS_BUILD_NUMBER}")

set(CPACK_PACKAGE_CONTACT osmironov@gmail.com)

include(CPack)