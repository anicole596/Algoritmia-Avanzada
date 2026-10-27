#include <iostream>
#include <map>
#include "../02_BuildingBlocks/Helpers.h"

#include <format>

static void map_example_1() {
    constexpr size_t epl_max {10};

    std::map<int, std::string> m1{

        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"},
        {0, "zero"},
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
    };
    auto print_resume = [&m1](const char* msg) {
        print_map("m1 (initial values): ", m1, epl_max);
        std::cout <<std::format("m1.size() : {:d}", m1.size()) << std::endl;
    };
}

int main() {
    std::cout << "Map!" << std::endl;

    return 0;

}