#include <mpi.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    MPI_Init(&argc, &argv);

    int nb_processes;
    MPI_Comm_size(MPI_COMM_WORLD, &nb_processes);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    printf("Hello World from process %d / %d \n", rank, nb_processes);

    MPI_Barrier(MPI_COMM_WORLD);

    MPI_Finalize();
    return 0;
}