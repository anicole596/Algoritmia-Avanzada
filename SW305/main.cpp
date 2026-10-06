#include <array>
#include <iostream>
#include <list>

#include "02_BuildingBlocks/Helpers.h"

static void list_example_1(){
    std::list<int> l1{20, 30, 40, 50, 60,70, 80};
    print_container("l1 (initial values:", l1);
    std::cout <<"l1.size(): "<< l1.size() << std::endl;
    std::cout <<"l1.front(): "<< l1.front() << std::endl;
    std::cout <<"l1.back(): "<< l1.back() << std::endl;
    std::cout <<"l1.size(): "<< l1.size() << std::endl;
    std::cout <<"l1.front(): "<< l1.front() << std::endl;
    std::cout <<"l1.back(): "<< l1.back() << std::endl;

    // push_back, push_front
    l1.push_front(10);
    l1.push_back(90);
    print_container("l1 (after push)", l1);
    std::cout <<"l1.size(): "<< l1.size() << std::endl;
    std::cout <<"l1.front(): "<< l1.front() << std::endl;
    std::cout <<"l1.back(): "<< l1.back() << std::endl;

    // std::advance
    auto it_mid = l1.begin();
    std::advance(it_mid, l1.size()/2 );
    std::cout <<"it_mid: "<< *it_mid << std::endl;

    // std::insert
    std::array<int, 3> more_values{-40, -50,-60};
    l1.insert(it_mid, more_values.begin(), more_values.end());
    print_container("l1 (after insert)", l1);
    std::cout <<"l1.size(): "<< l1.size() << std::endl;
    std::cout <<"l1.front(): "<< l1.front() << std::endl;
    std::cout <<"l1.back(): "<< l1.back() << std::endl;

    // std::remove
    l1.remove(40);
    l1.remove(70);
    print_container("l1 (after remove)", l1);
    std::cout <<"l1.size(): "<< l1.size() << std::endl;
    std::cout <<"l1.front(): "<< l1.front() << std::endl;
    std::cout <<"l1.back(): "<< l1.back() << std::endl;

    // remove_if
    auto rem_pred = [](int x) {return x % 60 == 0;}; //funcion predicado
    l1.remove_if(rem_pred);

    // pop_front, pop_back
    l1.pop_back();
    l1.pop_front();
    print_container("l1 (after pop)", l1);
    std::cout <<"l1.size(): "<< l1.size() << std::endl;
    std::cout <<"l1.front(): "<< l1.front() << std::endl;
    std::cout <<"l1.back(): "<< l1.back() << std::endl;
}

static void list_example_2(){
    std::list<std::string> l1{"Ene", "Feb", "Mar", "Abr", "Sep", "Oct", "Nov", "Dec"};
    std::list<std::string> l2{"May", "Jun", "Jul", "Ago"};
    print_container("l1 (initial values):", l1);
    print_container("l2 (initial values):", l2);

    //list::splice
    auto it_splice = l1.begin();
    std::cout <<"it_splice (initial value): "<< *it_splice << std::endl;
    std::advance(it_splice, l1.size()/2 );
    std::cout << "it_slice (after advance): " << *it_splice << std::endl;
    l1.splice(it_splice, l2);// Todos los valores de l2 se retiran de l2 y se pasan a l1
    print_container("l1 (after 1st splice):", l1);
    print_container("l2 (after 1st splice):", l2);
    std::cout << "it_slice (after splice): " << *it_splice << std::endl;
    l2.splice(l2.begin(), l1, l1.begin(), l1.end());
    print_container("l1 (after 2nd splice):", l1);
    print_container("l2 (after 2nd splice):", l2);
}

int main() {
    std::cout <<"List !!!" << std::endl;
    //list_example_1();
    list_example_2();
    return 0;
}