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

    print_resume("m1 (initial values) : ");


    // Use operator[] to change the values associated with existing keys.
    // The German words are example data and are intentionally preserved.
    std::cout << "\n--- Modifying existing values with operator[] ---" << std::endl;

    m1[0] = "null";
    m1[1] = "eins";
    m1[2] = "zwei";
    m1[3] = "drei";

    print_resume("m1 (after modifications) : ");


    // When a key is absent, operator[] inserts an entry before assigning its value.
    std::cout << "\n--- Adding new entries with operator[] ---" << std::endl;

    m1[10] = "zenh";
    m1[11] = "elf";

    std::cout<<std::endl;
    print_resume("m1 (after insertions) : ");


    // at() accesses the value associated with an existing key.
    // Unlike operator[], it throws std::out_of_range if the key is absent.
    std::cout << "\n--- Accessing an existing value with at() ---" << std::endl;

    std::cout << std::format ("m1.at({:d}) = {:s}", 2, m1.at(2)) <<std::endl;

    // Disabled example: key 45 is absent, so this call would throw an exception.
    //std::cout << std::format ("m1.at({:d}) = {:s}", 45, m1.at(45)) <<std::endl;


    // Remove the entries whose keys are 5 and 6.
    std::cout << "\n--- Erasing entries by key with erase() ---" << std::endl;

    m1.erase(5);
    m1.erase(6);

    std::cout<<std::endl;
    print_resume("m1 (after erasing) : ");


    // Remove every entry from the map.
    std::cout << "\n--- Removing all entries with clear() ---" << std::endl;

    m1.clear();

    std::cout<<std::endl;
    print_resume("m1 (after clear) : ");
}


static void map_example_2() {
    constexpr size_t epl_max{10};
    std::map<std::string_view, std::string> m1{
        {"ORD", "O'Hare International (Chicago, IL USA)"},
        {"LHR", "Heathrow Airpot (London, England UK)"},
        {"ZRH", "Flughanfen Zurich (Zurich, Switzerland)"},
        {"AKL", "Auckland Airpot (Auckland, New Zeland)"},
    };
    auto print_resume = [&m1](const char* msg) {
        print_map(msg, m1, epl_max);
        std::cout << std::format("m1.size(): {}", m1.size()) << std::endl;
    };
    print_resume("m1 (initial values) : ");
    // insert
    m1["SYD"] = "Sydney Airpot (Sydney, Australia)";
    print_resume("m1 (after insertions): ");
    std::pair p = std::make_pair("NRT", "Narita International (Tokyo, Japan)");
    auto [iter1, status1] = m1.emplace(p);
    if (status1) {
        std::cout << "m1.emplace() - new element add to map m1" << std::endl;
        std::cout << std::format("Key: {}, value: {}", iter1->first, iter1->second) << std::endl;
    } else {
        std::cout << "m1.emplace() - key element already exists at map m1" << std::endl;
        std::cout << std::format("Key: {}, value: {}", iter1->first, iter1->second) << std::endl;
    }
    // try_emplace
    auto [iter2, status2] = m1.try_emplace("DXB", "Dubai International Airpot (Dubai, UAE)");
    if (status2) {
        std::cout << "m1.try_emplace() - new element add to map m1" << std::endl;
        std::cout << std::format("Key {}, value {}", iter2->first, iter2->second) << std::endl;
    } else {
        std::cout << "m1.try_emplace() - key element already exists at map m1" << std::endl;
        std::cout << std::format("Key {}, value {}", iter2->first, iter2->second) << std::endl;
    }
    std::cout << std::endl;
    print_resume("m1 (after emplacements):");

    //Search
    std::array<std::string_view, 4> keys{"ZHR", "LAK", "MCD", "AKL"};
    for (const auto& key : keys) {
        std::cout << std::format("key: {}", key) << std::endl;
        auto iter = m1.find(key);
        if (iter != m1.end()) {
            std::cout << std::format("found [[{}, {}]", iter->first, iter-->second) << std::endl;
        }
    }
}

int main() {
    std::cout << "Map!" << std::endl;

    return 0;

}