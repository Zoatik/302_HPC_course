#include <mpi.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    MPI_Init(&argc, &argv);

    int nb_processes;
    MPI_Comm_size(MPI_COMM_WORLD, &nb_processes);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


    if (rank == 0) {
        printf("Number of processes: %d \n", nb_processes);
        printf("Hello World from process %d / %d \n", rank+1, nb_processes);
        for (int i = 1; i < nb_processes; i++) {
            MPI_Recv(NULL, 0, MPI_CHAR, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Hello World from process %d / %d \n", i+1, nb_processes);
        }
    }
    else {
        MPI_Send(NULL, 0, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }

    
    MPI_Finalize();
    return 0;
}