#include <mpi.h>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int number_processes;
    MPI_Comm_size(MPI_COMM_WORLD, &number_processes);

    string line;
    if (rank == 0){
        ifstream file;

        file.open("data.txt");
        if (!file.is_open()) {
            cerr << "File could not be read." << endl;
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        getline(file, line);
        file.close();
        
    }

    int line_size = static_cast<int>(line.size());
    MPI_Bcast(&line_size, 1, MPI_INT, 0, MPI_COMM_WORLD);

    line.resize(line_size);

    MPI_Bcast(line.data(), line_size, MPI_CHAR, 0, MPI_COMM_WORLD);

    cout << "process : " << rank << " -> " << line << endl;
    

    MPI_Finalize();

    return 0;
}