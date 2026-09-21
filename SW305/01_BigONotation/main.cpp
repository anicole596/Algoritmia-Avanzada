#include <iostream>
#include <random>
#include <chrono>

using namespace std;

static long long sumaMatrix(const int matrix[], int n) {
    long long sum = 0;
    for ( int i =0; i < n; i++) {
        sum += matrix[i];
    }
    return sum;
}

int main() {

    std::cout << "Big O Notation!" << std::endl;
    int size_of_n[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    const int SIZE_OF_N = sizeof(size_of_n) / sizeof(int);

    //Random number generador

    random_device rd;
    mt19937 generador(rd());
    uniform_int_distribution<> distribution(1, 100);
    const int N_EJECUCIONES = 20;
    for (int i = 0; i<SIZE_OF_N; i++) {
        int n = size_of_n[i];
        // array de n elementos
        int* matrix = new int[n];
        // llenar cada array
        for (int j = 0; j < n; j++) {
            matrix[j] = distribution(generador);
        }
        double totalTime = 0.0;
        long long resultado = 0;
        for (int j = 0; j < N_EJECUCIONES; j++) {
            auto  initialTime = chrono::high_resolution_clock::now();
            resultado = sumaMatrix(matrix, n);
            auto endTime = chrono::high_resolution_clock::now();
            double diffTime = chrono::duration<double, micro>(endTime - initialTime).count();
            totalTime += diffTime;
        }
        // tiempo promedio
        double averageTime = totalTime / N_EJECUCIONES;
        cout<< averageTime << ", ";
        delete [] matrix;
    }


    cout << " done !!!" << endl;
    return 0;
}
