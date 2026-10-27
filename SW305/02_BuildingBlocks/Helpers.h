//
// Created by HP on 4/10/2026.
//

#ifndef INC_2026_II_SW305_HELPERS_H
#define INC_2026_II_SW305_HELPERS_H

#include <iostream>
#include <map>

template <typename T>
static void print_container(const char *msg, const T &container, size_t epl_max = 0) {
    if (msg != nullptr) {
        std::cout << msg << std::endl;
    }

    if (container.empty()) {
        std::cout << "<empty>" <<std::endl;
    }

    size_t epl{};

    for (const auto &e : container) {
        std::cout << e << " ";

        if (epl_max != 0) {
            if (++epl % epl_max == 0) {
                std::cout << std::endl;
            }
        }
    }

    //if (num_elem == 0) {
       // std::cout << "<empty>" << std::endl;
    //}

    if (epl_max == 0 ||container.size() % epl_max != 0) {
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

template <typename T, typename U>
void print_multimap(const char *msg, const std::multimap<T, U> &container, const U &epl_max = 0) {
    if (msg != nullptr) {std::cout << msg << std::endl;}
    if (container.empty()) {std::cout << "<empty>" <<std::endl;return;}
    size_t epl {0};
    for (const auto &[key, value] : container) {
        std::cout << std::format("({}, {}) ", key, value);
        if (epl_max != 0) {
            if (++epl %epl_max == 0) {
                std::cout << std::endl;
            }
        }
    }

    if (epl_max == 0 ||container.size() % epl_max != 0) {
        std::cout << std::endl;
    }
}

template <typename T, typename U> //por que no se puede implementar un map a partir de un multimap
void print_map(const char *msg, const std::multimap<T, U> &container, size_t epl_max = 0) {
    std::multimap<T, U> map(container.begin(), container.end());
    print_multimap(msg, map, epl_max);
}

#endif //INC_2026_II_SW305_HELPERS_H