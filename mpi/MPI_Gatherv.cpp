#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int main(int argc, char **argv) {
  //  每个进程发送100＊150矩阵的第rank列的前（100－rank）个数
  // stride要>=rcounts［i]

  int gsize;
  int rank;
  int *rbuf, *displs, stride;
  int sendarray[100][150], *sptr;
  int *rcounts;
  int root = 0;
  MPI_Datatype stype;
  stride = 102;
  for (int i = 0; i < 100; i++)
    for (int j = 0; j < 150; j++) sendarray[i][j] = i * 150 + j;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &gsize);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  rbuf = (int *)malloc(gsize * stride * sizeof(int));
  displs = (int *)malloc(gsize * sizeof(int));
  //   rcounts = (int *)malloc(gsize * sizeof(int));
  rcounts = new int[gsize];
  for (int i = 0; i < gsize; i++) {
    displs[i] = i * stride;
    rcounts[i] = 100 - i;
  }
  // create the datatype for the column to be sent
  MPI_Type_vector(100 - rank, 1, 150, MPI_INT, &stype);
  MPI_Type_commit(&stype);
  /*sptr is the address of the start of rank column*/
  sptr = &sendarray[0][rank];
  MPI_Gatherv(sptr, 1, stype, rbuf, rcounts, displs, MPI_INT, root,
              MPI_COMM_WORLD);
  if (rank == 0) {
    for (int i = 0; i < gsize; i++) {
      for (int k = 0, j = displs[i]; k < rcounts[i]; k++)
        printf("%d\n", rbuf[j + k]);
    }
  }
  free(rbuf);
  free(displs);
  free(rcounts);

  MPI_Finalize();
}