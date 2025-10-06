#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank;
    char msg[50];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        sprintf(msg, "Hello from Process 0");
        MPI_Send(msg, 50, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(msg, 50, MPI_CHAR, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 0 received message: %s\n", msg);
    } else if (rank == 1) {
        MPI_Recv(msg, 50, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 1 received message: %s\n", msg);
        sprintf(msg, "Hello from Process 1");
        MPI_Send(msg, 50, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
