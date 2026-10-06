#include <iostream>
#include <list>

#include "02_BuildingBlocks/Helpers.h"

static void list_example_1(){
    std::list<int> l1{20, 30, 40, 50, 60,70, 80};
    print_container("l1 (initial values:", l1);
    std::cout <<"l1.size()"<< l1.size() << std::endl;
    std::cout <<"l1.size()"<< l1.front() << std::endl;
    std::cout <<"l1.size()"<< l1.back() << std::endl;
    std::cout <<"l1.size()"<< l1.size() << std::endl;
    std::cout <<"l1.size()"<< l1.front() << std::endl;
    std::cout <<"l1.size()"<< l1.back() << std::endl;

    // push_back, push_front
    l1.push_front(10);
    l1.push_back(90);
    print_container("l1 (after push)", l1);
    std::cout <<"l1.size()"<< l1.size() << std::endl;
    std::cout <<"l1.size()"<< l1.front() << std::endl;
    std::cout <<"l1.size()"<< l1.back() << std::endl;

    // std::advance
    auto it_mid = l1.begin();
    std::advance(it_mid, l1.size()/2 );
    std::cout <<"it_mid: "<< *it_mid << std::endl;

}
int main() {
    std::cout <<"List !!!" << std::endl;
    list_example_1();
    return 0;
}