#include <format>
#include <iostream>
#include <unordered_set>

template <typename T>
static void print_stats(const char* msg, const T& unordered_set) {
    //print stats
    std::cout << std::format("{:s}", msg) << std::endl;
    std::cout << std::format("size: {:d}", unordered_set.size()) << std::endl;
    std::cout << std::format("buckets_count: {:d}", unordered_set.bucket_count()) << std::endl;
    std::cout << std::format("load_factor: {:.4f}", unordered_set.load_factor()) << std::endl;
}

static void print_buckets(const char* msg, const std::unordered_set<std::string>& container) {
    print_stats(msg, container);

    //buckets
    for (size_t i = 0; i < container.bucket_count(); ++i) {
        if (container.bucket_size(i)) {
            std::cout << std::format("bucket {:2d}: ", i);
            for (auto iter = container.begin(i); iter != container.end(i); ++iter) {
                std::cout << std::format("'{}'", *iter);
            }
            std::cout << std::endl;
        }
    }
}

//static void unordered_set_example_1() {
static std::unordered_set<std::string> unordered_set_example_1(){
    std::unordered_set<std::string> us1 {
        "Golfo de Alaska",
        "Mar del Caribe",
        "Mar Negro",
        "Mar Rojo",
        "Golfo de Tailandia",
        "Mar de Bering",
    };
    print_buckets("us1 (initial values)", us1);

    //insert
    us1.insert("Mar Baltico");
    us1.insert("Mar Mediterraneo");
    us1.insert("Golfo de Mexico");
    us1.emplace("Mar Ross");
    us1.emplace("Mar de Greenland");
    us1.emplace("Mar Amarillo");
    print_buckets("us1 (after inset & emplace)", us1);
    std::array<std::string, 6> a1 {
        "Mar Labrador",
        "Golfo Admusend",
        "Mar del Norte",
        "Mar Adriatico",
        "Mar de las Antillas Australes",
        "Golfo Vizcaya",
       };

#if __cpp_lib_containers_range >= 201402L
    us1.insert_ranges(a1);
    print_buckets("us1 (after insert_ranges)", us1);
#else
    std::ranges::copy(a1, std::inserter(us1, us1.begin()));
    print_buckets("us1 (after ranges::copy)", us1);
#endif

    return us1;
}

static void unordered_set_example_2(std::unordered_set<std::string> us1) {
    //create us2
    std::unordered_set<std::string> us2 {
        "Mar Amarillo",
        "Mar Rojo",
        "Mar Arabico",
        "Bahia de Baffin",
        "Mar del Norte",
        "Mar de Beauford",
        "Mar Caspio",
        "Golfo de Biscay",
    };
    print_buckets("us1 (initial values)", us1);
    print_buckets("us2 (initial values)", us2);

    //merge
    us2.merge(us1); // se pasan solo los que no existen
    print_buckets("us1 (after merge)", us1);
    print_buckets("us2 (after merge)", us2);

    //contains
    std::cout << std::format("s2.contains('Mar de Java'): {}", us2.contains("Mar de Java")) << std::endl;
    std::cout << std::format("s2.contains('Mar del Norte'): {}", us2.contains("Mar del Norte")) << std::endl;

    //extract
    std::array<std::string, 3> extract_seas {
        "Mar Negro", "Mar Verde", "Mar Rojo"
    };

    for (const auto &extract_seas : extract_seas) {
        std::cout << std::format("extract_sea: {:s}" ,extract_seas)<< std::endl;
    }

    std::cout << std::endl;
}

int main(){
    std::cout << "Unordered set!!" << std::endl;
    //unordered_set_example_1();
    unordered_set_example_2 (unordered_set_example_1());

    return 0;

}