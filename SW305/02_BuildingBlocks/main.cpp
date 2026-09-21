#include <iostream>

//Plantilla de Swap para cualquier tipo de dato
template <typename T>
static void Swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

static void Print(const int A[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cout << A[i] <<" ";
    }
}

template <typename T>
static void Print2(const T& array) {
    for (auto element : array) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Building Blocks!!!" << std::endl;
    int A[]={5,8};

    //Print(A, 2);
    Print2(A);

    Swap(A[0], A[1]);

    //Print(A, 2);
    Print2(A);

    return 0;
}
