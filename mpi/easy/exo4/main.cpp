#include <mpi.h>
#include <stdio.h>
#include <cstdlib>

const int SIZE = 200;
const int SEED = 42;

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    int nb_processes;
    MPI_Comm_size(MPI_COMM_WORLD, &nb_processes);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (SIZE % nb_processes != 0) {
        if (rank == 0)
            printf("SIZE (%d) must be divisible by nb_processes (%d)\n", SIZE, nb_processes);

        MPI_Finalize();
        return 1;
    }

    int array_div_size = SIZE / nb_processes;

    int* table = nullptr;

    if (rank == 0) {
        table = new int[SIZE];

        srand(SEED);
        for (int i = 0; i < SIZE; i++) {
            table[i] = rand() % 10000 - 5000;
        }
    }

    // Local table for each processors
    int* local_table = new int[array_div_size];

    // Distribution
    MPI_Scatter(
        table,
        array_div_size,
        MPI_INT,
        local_table,
        array_div_size,
        MPI_INT,
        0,
        MPI_COMM_WORLD
    );

    int local_sum = 0;

    for (int i = 0; i < array_div_size; i++) {
        local_sum += local_table[i];
    }


    // Collector table
    int* sums = nullptr;

    if (rank == 0) {
        sums = new int[nb_processes];
    }

    // Gather infos from all processors
    MPI_Gather(
        &local_sum,
        1,
        MPI_INT,
        sums,
        1,
        MPI_INT,
        0,
        MPI_COMM_WORLD
    );

    if (rank == 0) {
        int total_sum = 0;

        for (int i = 0; i < nb_processes; i++) {
            total_sum += sums[i];
            printf("Rank %d: local sum = %d\n", i, sums[i]);
        }

        printf("Total sum = %d\n", total_sum);

        delete[] table;
        delete[] sums;
    }

    delete[] local_table;

    MPI_Finalize();
    return 0;
}