#include <iostream>
#include <format>
#include <set>
#include <string>
#include "../02_BuildingBlocks/Helpers.h"

//epl elementos por linea
static void set_example_1(){

    constexpr size_t epl_max{10};

    // create set
    std::set<int> s1{20, 40, 100, 50, 90, 70, 10, 30};

    auto print_resume = [&s1](const char* msg) -> void {
        print_container(msg, s1, epl_max);
        std::cout << std::format("s1.size(): {}", s1.size()) << std::endl;
    };

    // print_container("s1 (initial values):", s1, epl_max);
    // std::cout << std::format("s1.size(): {}", s1.size()) << std::endl;

    print_resume("s1 (initial values):");

    // add elements
    std::array<int, 3> a1{80, 50, 60};

    for (auto val : a1) {
        auto p = s1.insert(val);
        std::cout << std::format("({:d}, {:s})", *p.first, p.second)
                  << std::endl;
    }

    // print_container("s1 (after insertions):", s1, epl_max);

    print_resume("s1 (after insertions): ");
    //create set<<std::strings>
    std::set<std::string> s2{"New york", "Los Angeles", "Chicago", "Houston", "Phoenix", "Philadelphia", "San Antonio", "San Diego"};
    auto print_resume2 = [&s2](const char* msg) -> void {
        print_container(msg, s2, epl_max);
        std::cout << std::format("s2.size(): {}", s2.size()) << std::endl;
    };
    print_resume2("s2 (initial values):");
    //add elements
    std::array<std::string, 3> a2{"Dallas", "Phoenix", "Austin"};
    for(const auto& val : a2){
        auto p = s2.emplace(val);
        std::cout<<std::format("({:s},{:s})", *p.first, p.second)<<std::endl;
    }
    print_resume2("s2 (after emplacements) :");
}

static void set_example_2(){
    constexpr size_t epl_max{10};

    std::set<std::string, std::greater<std::string>> s1{
            "California", "Texas", "Florida",
            "New York", "Pennsylvania", "Illinois", "Ohio"
    };

    auto print_resume = [&s1](const char* msg) -> void {
        print_container(msg, s1, epl_max);
        std::cout << std::format("s1.size(): {}", s1.size())
                  << std::endl;
    };

    print_resume("s1 (initial values):");

    // add elements
    std::array<std::string, 4> a1{"Georgia", "Florida", "North Carolina", "Michigan"};
    s1.insert(a1.begin(), a1.end());
    print_resume("s1 (after insertion) :");

#ifdef __cpp_lib_containers_ranges
    std::array<std::stirng, 3> a2 {"South Carolina", "Vermont", "Indiana"}
    a1.insert(a1.begin(), a1.end());
    print_resume("a1 (after insertions):");

#else
    std::cout<< "std::set::insert_range() require C++ 23" << std::endl;

#endif

    //iteratos
    for (auto it = s1.begin(); it != s1.end(); ++it) {
        std::cout << std::format("({:s})", *it) << std::endl;
    }
}

static void set_example_3() {
    constexpr size_t epl_max{10};

    std::set<int> s1{100, 200, 300, 400, 500, 600};
    std::set<int> s2{100, 150, 300, 400, 500, 600};
    std::set<int> s3{100, 200, 300, 400, 500, 600};
    std::set<int> s4{100, 200, 300, 450, 500, 600};

    print_container("s1 (initial values):", s1, epl_max);
    print_container("s2 (initial values):", s2, epl_max);
    print_container("s3 (initial values):", s3, epl_max);
    print_container("s4 (initial values):", s4, epl_max);
    std::cout<< std::format("s1 == s2: {:s}", s1 == s2)<< std::endl;
    std::cout<< std::format("s1 != s2: {:s}", s1 != s2)<< std::endl;
    std::cout<< std::format("s1 < s2: {:s}", s1 < s2)<< std::endl;
    std::cout<< std::format("s1 <= s2: {:s}", s1 <= s2)<< std::endl;
    std::cout<< std::format("s1 > s2: {:s}", s1 > s2)<< std::endl;
    std::cout<< std::format("s1 >= s2: {:s}", s1 >= s2)<< std::endl;

    std::cout<< std::format("s1 == s3: {:s}", s1 == s2)<< std::endl;
    std::cout<< std::format("s1 != s3: {:s}", s1 != s2)<< std::endl;
    std::cout<< std::format("s1 < s3: {:s}", s1 < s2)<< std::endl;
    std::cout<< std::format("s1 <= s3: {:s}", s1 <= s2)<< std::endl;
    std::cout<< std::format("s1 > s3: {:s}", s1 > s2)<< std::endl;
    std::cout<< std::format("s1 >= s3: {:s}", s1 >= s2)<< std::endl;

    std::cout<< std::format("s1 == s4: {:s}", s1 == s2)<< std::endl;
    std::cout<< std::format("s1 != s4: {:s}", s1 != s2)<< std::endl;
    std::cout<< std::format("s1 < s4: {:s}", s1 < s2)<< std::endl;
    std::cout<< std::format("s1 <= s4: {:s}", s1 <= s2)<< std::endl;
    std::cout<< std::format("s1 > s4: {:s}", s1 > s2)<< std::endl;
    std::cout<< std::format("s1 >= s4: {:s}", s1 >= s2)<< std::endl;

    using set_t = std::set<int, std::greater<int>>;
    set_t s5 {100, 200, 300, 400, 200, 500};
    set_t s6 {100, 200, 300, 400, 200, 500};
    set_t s7 {100, 200, 300, 400, 200, 500};

    std::cout<< std::format("s5 == s6: {:s}", s5 == s6)<< std::endl;
    std::cout<< std::format("s5 < s6: {:s}", s5 < s6)<< std::endl;
    std::cout<< std::format("s5 > s6: {:s}", s5 > s6)<< std::endl;

    std::cout<< std::format("s5 == s7: {:s}", s5 == s7)<< std::endl;
    std::cout<< std::format("s5 < s7: {:s}", s5 < s7)<< std::endl;
    std::cout<< std::format("s5 > s7: {:s}", s5 > s7)<< std::endl;
}

static void set_example_4() {
    constexpr size_t epl_max{10};

    //create set<string>
    std::set<std::string> s1 { "Wyoming", "Alaska", "North Dakota", "South Dakota", "Delaware", "Rhode island", "Montana", "Maine"};
    print_container("s1 (initial values):", s1, epl_max);

    //search using find
    std::array< std::string,4> find_vals {"New Hampshire", "Alaska", "Hawaii", "Maine"};

    for (const auto& find_val : find_vals) {
        std::cout<<std::format("s1.find_val: {:s} - ", find_val);
        auto it = s1.find(find_val); //devuelve iterador si no encuentra devuelve el ultimo
        if (it != s1.end()) {
            s1.erase(it);
            std::cout <<"removed!";
        }else {
            std::cout<<"not found!";
        }
        std::cout << std::endl;
    }
    print_container("s1(after erase operation", s1, epl_max);

    //function contains
    std::array<std::string,3> contains_vals {"Kansas", "South Dakota", "Nebraska"};
    for (const auto& contains_val : contains_vals) {
        bool b = s1.contains(contains_val);
        std::cout<<std::format("s1.contains({:s}): {:s}", contains_val, b)<< std::endl;
    }
}

static void set_example_5() {
    using namespace std::numbers;

    //create sets
    std::set<double> s1 {pi, e, inv_pi, sqrt2};
    std::set<double> s2 {sqrt2, phi, pi, sqrt3, log2e};
    print_container("s1 (initial values):", s1);
    print_container("s2 (initial values):", s2);

    //merge
    s1.merge(s2);
    print_container("s1 (after merge operation)", s1);
    print_container("s2 (after merge operation)", s2);

    //clear
    s1.clear();
    print_container("s1 (after clear operation)", s1);

}

static void multiset_example_6() {
    constexpr size_t epl_max{10};
    std::multiset<int> ms1 {20, 40, 100, 50, 90, 70, 10, 80, 30};
    auto print_resume = [&ms1](const char* msg) {
        print_container(msg, ms1, epl_max);
        std::cout<< std::format("ms1.size(): {}", ms1.size())<< std::endl;
    };
    print_resume("ms1 (initial values): ");

    //sdd elements
    ms1.insert(100);
    ms1.insert(190);
    ms1.insert(80);
    ms1.insert(60);
    print_resume("s1 (after insertions): ");

    //count
    int count_val {80};
    size_t n =ms1.count(count_val);
    std::cout<< std::format("ms1.count({:d}): {:d}", count_val, n)<< std::endl;
}

static void multiset_example_7() {
    constexpr size_t epl_max{10};
    std::multiset<std::string, std::greater<std::string>> ms1 {"Pitsburg", "Atlanta", "Charlotte", "Denver", "Seattle", "Miami", "Atlanta", "Dallas", "Denver", "Boise"};
    std::cout<< std::format("ms1.size(): {}", ms1.size())<< std::endl;
}

int main(){
    std::cout<<"Set !!!"<<std::endl;
    //set_example_1();
    //set_example_2();
    //set_example_3();
    //set_example_4();
    //set_example_5();
    //multiset_example_6();
    return 0;
}