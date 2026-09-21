#include <iostream>
#include <array>
#include <format>


static void array_example_1() {
    std::array <int, 9> x_vals {100, 200, 300, 400, 500, 600, 700, 800, 900} ;
    std::cout << "x_vals[0] "<< std::endl;

    // Para todo tipo de contenedo
    for (int i = 0; i < x_vals.size(); i++) {
        std::cout << x_vals.at(i) << " ";
    }
    std::cout << std::endl;

    // Formato comun
    for (auto value : x_vals) {
        std::cout << value <<" ";
    }
    std::cout << std::endl;

    // Formato utilizando la libreria format
    for (auto value : x_vals) {
        std::cout << std :: format("{:6d}", value);
    }
    std::cout << std::endl;

    std::cout <<"size: "<< x_vals.size() << std::endl;

    // Iteradores
    for (auto it = x_vals.begin(); it != x_vals.end(); ++it) {
        std::cout << std :: format("{:7d} ", *it); // *it desrefernciador
    }
    std::cout << std::endl;

    // Iterador reverso
    for (auto it = x_vals.rbegin(); it != x_vals.rend(); ++it) {
        std::cout << std :: format("{:7d} ", *it);
    }

}

static void array_example_2(){
    std:: array<long, 10> x_vals {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    for (auto it = x_vals.begin(); it != x_vals.end(); ++it) {
        std::cout << std :: format("{:6d}", *it);
    }
    std::cout << std::endl;

    // Agregamos 5  a cada elemento
    for (auto it = x_vals.begin(); it != x_vals.end(); ++it) {
        *it += 5;
        std::cout << std :: format("{:6d}", *it);
    }
    std::cout << std::endl;
}

int main() {

    std::cout << "Arrays!!! "<< std::endl;
    //array_example_1();
    array_example_2();

    return 0;
}