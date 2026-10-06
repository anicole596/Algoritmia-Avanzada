#include <array>
#include <iostream>
#include <list>

#include "../02_BuildingBlocks/Helpers.h"

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

static void list_example_3() {
    std::list<int> l1{10, 20, 30, 40, 50, 60,70, 80};
    std::list<int> l2{-1, -2, -3, -4, -5, -6, -7, -8};
    std::list<int> l3(l1.size());
    if (l1.size() != l2.size()) {
        throw std::runtime_error("Las longitudes de las listas deben ser iguales");
    }
    print_container("l1 (initial values):", l1);
    print_container("l2 (initial values):", l2);
    print_container("l3 (initial values):", l3);

    // iteradores
    auto it1 = l1.cbegin();
    auto it2 = l2.cbegin();
    auto it3 = l3.begin();
    for (; it1 !=l1.cend(); ++it1, ++it2) {
        *it3++ = *it1 + *it2; //el ++ trae el siguiente puntero
    }
    print_container("l3 (after clear)", l3);
}

static void list_example_4() {
    std::list<std::string> l1{};
    std::list<std::string> l2{};
    l1.emplace_back("Peru");
    l2.emplace_back("Argentina");
    l1.emplace_front("Chile");
    l2.emplace_front("Brazil");
    l1.emplace_back("Uruguay");
    l2.emplace_back("Paraguay");
    l1.emplace_front("Colombia");
    l2.emplace_front("Ecuador");
    l1.emplace_back("Bolivia");
    l2.emplace_back("Venezuela");
    l1.emplace_front("Paraguay");
    l2.emplace_front("Costa Rica");
    l1.emplace_back("Nicaragua");
    l2.emplace_back("Guyana");
    l1.emplace_front("Guyana Francesa");
    l2.emplace_front("Suriman");

    //print
    print_container("l1 (initial values)", l1);
    print_container("l2 (initial values)", l2);

    //list::sort
    l1.sort();
    l2.sort();
    print_container("l1 (after sort)", l1);
    print_container("l2 (after sort)", l2);

    //list::merge
    l1.merge(l2);
    print_container("l1 (after merge)", l1);
    print_container("l2 (after merge)", l2);

    //list::reverse
    l1.reverse();
    print_container("l1 (after reverse)", l1);

}

int main() {
    std::cout <<"List !!!" << std::endl;
    //list_example_1();
    //list_example_2();
    //list_example_3();
    list_example_4();
    return 0;
}