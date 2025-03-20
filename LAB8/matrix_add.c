#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ROWS 3
#define COLS 3

int mat1[ROWS][COLS] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

int mat2[ROWS][COLS] = {
    {9, 8, 7},
    {6, 5, 4},
    {3, 2, 1}
};

int result[ROWS][COLS];

void* add_row(void* arg) {
    int row = *(int*)arg;
    free(arg);  

    for (int j = 0; j < COLS; j++) {
        result[row][j] = mat1[row][j] + mat2[row][j];
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[ROWS];

    for (int i = 0; i < ROWS; i++) {
        int *row = malloc(sizeof(int));
        if (row == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        *row = i;
        pthread_create(&threads[i], NULL, add_row, row);
    }

    for (int i = 0; i < ROWS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Matrix Addition (Using Globals):\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
