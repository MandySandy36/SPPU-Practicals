#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

// Swap function
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Sequential quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main(int argc, char* argv[]) {
    int rank, size;
    int n = 16; // total elements
    int *data = NULL;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int local_n = n / size;
    int *local_data = (int*)malloc(local_n * sizeof(int));

    // Master initializes data
    if (rank == 0) {
        data = (int*)malloc(n * sizeof(int));
        printf("Original array:\n");
        for (int i = 0; i < n; i++) {
            data[i] = rand() % 100;
            printf("%d ", data[i]);
        }
        printf("\n");
    }

    // Scatter data
    MPI_Scatter(data, local_n, MPI_INT,
                local_data, local_n, MPI_INT,
                0, MPI_COMM_WORLD);

    // Each process sorts its part
    quicksort(local_data, 0, local_n - 1);

    // Gather sorted parts
    MPI_Gather(local_data, local_n, MPI_INT,
               data, local_n, MPI_INT,
               0, MPI_COMM_WORLD);

    // Final merge at root
    if (rank == 0) {
        quicksort(data, 0, n - 1);

        printf("\nSorted array:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}
// mpicc filename.c -o filename
// mpirun -np 4 ./filename