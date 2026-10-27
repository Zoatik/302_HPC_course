#include <cstdlib>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[]){

    if (argc < 2){
        return -1;
    }

    for (size_t l = 0; l < argc - 1; l++){
        unsigned n = stoi(argv[l+1]);
        int* matrix = new int[n*n];

        for (size_t j = 0; j < n*n; j++){
            matrix[j] = rand() % 100000; 
        }

        int* out_matrix = new int[n*n]{0};


        // multiply the matrix with itself
        auto start = high_resolution_clock::now();
        for (size_t i = 0; i < n; i++){
            for (size_t j = 0; j < n; j++){
                for (size_t k = 0; k < n; k++){
                    out_matrix[i*n + j] += matrix[i*n + k] * matrix[k*n + j];
                }
            }
        }
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        printf("Time taken to multiply %d x %d matrix: %d microseconds\n", n, n, static_cast<int>(duration.count()));

        delete [] out_matrix;
        delete [] matrix;


        // display the out matrix
        /*for (size_t i = 0; i < 10; i++){
            for (size_t j = 0; j < 10; j++){
                printf("%d ", out_matrix[i*10 + j]);
            }
            printf("\n");
        }
        
        printf("\n");*/

    }

    return 0;
}