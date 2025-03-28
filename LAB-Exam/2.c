// 1. Matrix Addition

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// #define ROWS 3
// #define COLS 3

// int A[ROWS][COLS] = {
//     {1, 2, 3},
//     {4, 5, 6},
//     {7, 8, 9}
// };
// int B[ROWS][COLS] = {
//     {9, 8, 7},
//     {6, 5, 4},
//     {3, 2, 1}
// };
// int C[ROWS][COLS];  // Resultant matrix

// typedef struct {
//     int row;
// } thread_data;

// void* addRow(void* arg) {
//     thread_data* data = (thread_data*)arg;
//     int row = data->row;
//     for (int j = 0; j < COLS; j++) {
//         C[row][j] = A[row][j] + B[row][j];
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     pthread_t threads[ROWS];
//     thread_data thread_args[ROWS];
    
//     for (int i = 0; i < ROWS; i++) {
//         thread_args[i].row = i;
//         pthread_create(&threads[i], NULL, addRow, (void*)&thread_args[i]);
//     }
//     for (int i = 0; i < ROWS; i++) {
//         pthread_join(threads[i], NULL);
//     }
    
//     printf("Matrix Addition Result:\n");
//     for (int i = 0; i < ROWS; i++){
//         for (int j = 0; j < COLS; j++){
//             printf("%d ", C[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }


// 2. Matrix Multiplication

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// #define ROWS_A 3
// #define COLS_A 3
// #define ROWS_B 3
// #define COLS_B 3

// int A[ROWS_A][COLS_A] = {
//     {1, 2, 3},
//     {4, 5, 6},
//     {7, 8, 9}
// };
// int B[ROWS_B][COLS_B] = {
//     {9, 8, 7},
//     {6, 5, 4},
//     {3, 2, 1}
// };
// int C[ROWS_A][COLS_B];  // Resultant matrix

// typedef struct {
//     int row;
// } thread_data;

// void* multiplyRow(void* arg) {
//     thread_data* data = (thread_data*)arg;
//     int row = data->row;
//     for (int j = 0; j < COLS_B; j++) {
//         C[row][j] = 0;
//         for (int k = 0; k < COLS_A; k++) {
//             C[row][j] += A[row][k] * B[k][j];
//         }
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     pthread_t threads[ROWS_A];
//     thread_data thread_args[ROWS_A];
    
//     for (int i = 0; i < ROWS_A; i++) {
//         thread_args[i].row = i;
//         pthread_create(&threads[i], NULL, multiplyRow, (void*)&thread_args[i]);
//     }
//     for (int i = 0; i < ROWS_A; i++) {
//         pthread_join(threads[i], NULL);
//     }
    
//     printf("Matrix Multiplication Result:\n");
//     for (int i = 0; i < ROWS_A; i++){
//         for (int j = 0; j < COLS_B; j++){
//             printf("%d ", C[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }


// 3. Matrix Transpose

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// #define ROWS 3
// #define COLS 3

// int A[ROWS][COLS] = {
//     {1, 2, 3},
//     {4, 5, 6},
//     {7, 8, 9}
// };
// int T[COLS][ROWS];  // Transposed matrix

// typedef struct {
//     int row;
// } thread_data;

// void* transposeRow(void* arg) {
//     thread_data* data = (thread_data*)arg;
//     int row = data->row;
//     for (int j = 0; j < COLS; j++) {
//         T[j][row] = A[row][j];
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     pthread_t threads[ROWS];
//     thread_data thread_args[ROWS];
    
//     for (int i = 0; i < ROWS; i++) {
//         thread_args[i].row = i;
//         pthread_create(&threads[i], NULL, transposeRow, (void*)&thread_args[i]);
//     }
//     for (int i = 0; i < ROWS; i++) {
//         pthread_join(threads[i], NULL);
//     }
    
//     printf("Transposed Matrix:\n");
//     for (int i = 0; i < COLS; i++){
//         for (int j = 0; j < ROWS; j++){
//             printf("%d ", T[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }


// 4. Determinant Calculation (3×3 Matrix)

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// typedef struct {
//     int a, b, c, d;
//     int index;
// } thread_data;

// int minors[3];  // To store determinants of 2x2 minors

// void* compute_minor(void* arg) {
//     thread_data* data = (thread_data*)arg;
//     int det2 = data->a * data->d - data->b * data->c;
//     minors[data->index] = det2;
//     pthread_exit(NULL);
// }

// int main() {
//     int A[3][3] = {
//         {1, 2, 3},
//         {0, 4, 5},
//         {1, 0, 6}
//     };
    
//     pthread_t threads[3];
//     thread_data thread_args[3];
    
//     // Minor for A[0][0] (exclude row 0, col 0)
//     thread_args[0].a = A[1][1]; thread_args[0].b = A[1][2];
//     thread_args[0].c = A[2][1]; thread_args[0].d = A[2][2];
//     thread_args[0].index = 0;
//     pthread_create(&threads[0], NULL, compute_minor, (void*)&thread_args[0]);
    
//     // Minor for A[0][1] (exclude row 0, col 1)
//     thread_args[1].a = A[1][0]; thread_args[1].b = A[1][2];
//     thread_args[1].c = A[2][0]; thread_args[1].d = A[2][2];
//     thread_args[1].index = 1;
//     pthread_create(&threads[1], NULL, compute_minor, (void*)&thread_args[1]);
    
//     // Minor for A[0][2] (exclude row 0, col 2)
//     thread_args[2].a = A[1][0]; thread_args[2].b = A[1][1];
//     thread_args[2].c = A[2][0]; thread_args[2].d = A[2][1];
//     thread_args[2].index = 2;
//     pthread_create(&threads[2], NULL, compute_minor, (void*)&thread_args[2]);
    
//     for (int i = 0; i < 3; i++) {
//         pthread_join(threads[i], NULL);
//     }
    
//     // Cofactor expansion along the first row
//     int det = A[0][0] * minors[0] - A[0][1] * minors[1] + A[0][2] * minors[2];
//     printf("Determinant = %d\n", det);
//     return 0;
// }

// 5. Matrix Inversion (3×3 Matrix using Gauss-Jordan Elimination)

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// #define N 3

// double A[N][N] = {
//     {4, 7, 2},
//     {3, 6, 1},
//     {2, 5, 3}
// };
// double I[N][N] = {
//     {1, 0, 0},
//     {0, 1, 0},
//     {0, 0, 1}
// };

// typedef struct {
//     int pivot;
//     int row;
// } thread_data;

// void* eliminate(void* arg) {
//     thread_data* data = (thread_data*)arg;
//     int i = data->row;
//     int p = data->pivot;
//     double factor = A[i][p];
//     for (int j = 0; j < N; j++) {
//         A[i][j] -= factor * A[p][j];
//         I[i][j] -= factor * I[p][j];
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     for (int p = 0; p < N; p++) {
//         // Normalize the pivot row
//         double pivot = A[p][p];
//         if (pivot == 0) {
//             printf("Singular matrix.\n");
//             return -1;
//         }
//         for (int j = 0; j < N; j++) {
//             A[p][j] /= pivot;
//             I[p][j] /= pivot;
//         }
        
//         pthread_t threads[N];
//         thread_data thread_args[N];
//         int thread_count = 0;
//         // Eliminate the pivot column for all rows except the pivot row
//         for (int i = 0; i < N; i++) {
//             if (i != p) {
//                 thread_args[thread_count].pivot = p;
//                 thread_args[thread_count].row = i;
//                 pthread_create(&threads[thread_count], NULL, eliminate, (void*)&thread_args[thread_count]);
//                 thread_count++;
//             }
//         }
//         for (int i = 0; i < thread_count; i++) {
//             pthread_join(threads[i], NULL);
//         }
//     }
    
//     printf("Inverse Matrix:\n");
//     for (int i = 0; i < N; i++){
//         for (int j = 0; j < N; j++){
//             printf("%lf ", I[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// 6. Row-wise Sum with Threads


// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// #define ROWS 3
// #define COLS 3

// int A[ROWS][COLS] = {
//     {1, 2, 3},
//     {4, 5, 6},
//     {7, 8, 9}
// };

// int rowSums[ROWS];

// typedef struct {
//     int row;
// } thread_data;

// void* computeRowSum(void* arg) {
//     thread_data* data = (thread_data*)arg;
//     int row = data->row;
//     int sum = 0;
//     for (int j = 0; j < COLS; j++) {
//         sum += A[row][j];
//     }
//     rowSums[row] = sum;
//     pthread_exit(NULL);
// }

// int main() {
//     pthread_t threads[ROWS];
//     thread_data thread_args[ROWS];
    
//     for (int i = 0; i < ROWS; i++) {
//         thread_args[i].row = i;
//         pthread_create(&threads[i], NULL, computeRowSum, (void*)&thread_args[i]);
//     }
//     for (int i = 0; i < ROWS; i++) {
//         pthread_join(threads[i], NULL);
//     }
    
//     for (int i = 0; i < ROWS; i++) {
//         printf("Sum of row %d: %d\n", i, rowSums[i]);
//     }
//     return 0;
// }


// 7. Column-wise Mean Calculation

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// #define ROWS 3
// #define COLS 3

// int A[ROWS][COLS] = {
//     {1, 2, 3},
//     {4, 5, 6},
//     {7, 8, 9}
// };

// double colMeans[COLS];

// typedef struct {
//     int col;
// } thread_data;

// void* computeColMean(void* arg) {
//     thread_data* data = (thread_data*)arg;
//     int col = data->col;
//     int sum = 0;
//     for (int i = 0; i < ROWS; i++) {
//         sum += A[i][col];
//     }
//     colMeans[col] = (double)sum / ROWS;
//     pthread_exit(NULL);
// }

// int main() {
//     pthread_t threads[COLS];
//     thread_data thread_args[COLS];
    
//     for (int j = 0; j < COLS; j++) {
//         thread_args[j].col = j;
//         pthread_create(&threads[j], NULL, computeColMean, (void*)&thread_args[j]);
//     }
//     for (int j = 0; j < COLS; j++) {
//         pthread_join(threads[j], NULL);
//     }
    
//     for (int j = 0; j < COLS; j++) {
//         printf("Mean of column %d: %lf\n", j, colMeans[j]);
//     }
//     return 0;
// }

// 8. Parallel Matrix Scalar Multiplication

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// #define ROWS 3
// #define COLS 3

// int A[ROWS][COLS] = {
//     {1, 2, 3},
//     {4, 5, 6},
//     {7, 8, 9}
// };
// int result[ROWS][COLS];
// int scalar = 3;

// typedef struct {
//     int row;
// } thread_data;

// void* scalarMultiply(void* arg) {
//     thread_data* data = (thread_data*)arg;
//     int row = data->row;
//     for (int j = 0; j < COLS; j++) {
//         result[row][j] = A[row][j] * scalar;
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     pthread_t threads[ROWS];
//     thread_data thread_args[ROWS];
    
//     for (int i = 0; i < ROWS; i++) {
//         thread_args[i].row = i;
//         pthread_create(&threads[i], NULL, scalarMultiply, (void*)&thread_args[i]);
//     }
//     for (int i = 0; i < ROWS; i++) {
//         pthread_join(threads[i], NULL);
//     }
    
//     printf("Matrix after Scalar Multiplication (by %d):\n", scalar);
//     for (int i = 0; i < ROWS; i++){
//         for (int j = 0; j < COLS; j++){
//             printf("%d ", result[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// 9. Matrix Subtraction

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// #define ROWS 3
// #define COLS 3

// int A[ROWS][COLS] = {
//     {9, 8, 7},
//     {6, 5, 4},
//     {3, 2, 1}
// };
// int B[ROWS][COLS] = {
//     {1, 2, 3},
//     {4, 5, 6},
//     {7, 8, 9}
// };
// int C[ROWS][COLS];  // Resultant matrix

// typedef struct {
//     int row;
// } thread_data;

// void* subtractRow(void* arg) {
//     thread_data* data = (thread_data*)arg;
//     int row = data->row;
//     for (int j = 0; j < COLS; j++) {
//         C[row][j] = A[row][j] - B[row][j];
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     pthread_t threads[ROWS];
//     thread_data thread_args[ROWS];
    
//     for (int i = 0; i < ROWS; i++){
//         thread_args[i].row = i;
//         pthread_create(&threads[i], NULL, subtractRow, (void*)&thread_args[i]);
//     }
//     for (int i = 0; i < ROWS; i++){
//         pthread_join(threads[i], NULL);
//     }
    
//     printf("Matrix Subtraction Result (A - B):\n");
//     for (int i = 0; i < ROWS; i++){
//         for (int j = 0; j < COLS; j++){
//             printf("%d ", C[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// 10. Combining Operations:

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// #define ROWS 3
// #define COLS 3

// int A[ROWS][COLS] = {
//     {1, 2, 3},
//     {4, 5, 6},
//     {7, 8, 9}
// };
// int B[ROWS][COLS] = {
//     {9, 8, 7},
//     {6, 5, 4},
//     {3, 2, 1}
// };
// int D[ROWS][COLS] = {
//     {1, 0, 2},
//     {0, 1, 2},
//     {2, 1, 0}
// };

// int sumMatrix[ROWS][COLS];  // Holds A+B
// int result[ROWS][COLS];     // Holds (A+B)*D

// typedef struct {
//     int row;
// } thread_data;

// void* addRowOp(void* arg) {
//     thread_data* data = (thread_data*)arg;
//     int row = data->row;
//     for (int j = 0; j < COLS; j++) {
//         sumMatrix[row][j] = A[row][j] + B[row][j];
//     }
//     pthread_exit(NULL);
// }

// void* multiplyRowOp(void* arg) {
//     thread_data* data = (thread_data*)arg;
//     int row = data->row;
//     for (int j = 0; j < COLS; j++){
//         result[row][j] = 0;
//         for (int k = 0; k < COLS; k++){
//             result[row][j] += sumMatrix[row][k] * D[k][j];
//         }
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     pthread_t threads[ROWS];
//     thread_data thread_args[ROWS];
    
//     // Step 1: Matrix addition (A + B)
//     for (int i = 0; i < ROWS; i++){
//         thread_args[i].row = i;
//         pthread_create(&threads[i], NULL, addRowOp, (void*)&thread_args[i]);
//     }
//     for (int i = 0; i < ROWS; i++){
//         pthread_join(threads[i], NULL);
//     }
    
//     // Step 2: Matrix multiplication (sumMatrix * D)
//     for (int i = 0; i < ROWS; i++){
//         thread_args[i].row = i;
//         pthread_create(&threads[i], NULL, multiplyRowOp, (void*)&thread_args[i]);
//     }
//     for (int i = 0; i < ROWS; i++){
//         pthread_join(threads[i], NULL);
//     }
    
//     printf("Result of (A+B)*D:\n");
//     for (int i = 0; i < ROWS; i++){
//         for (int j = 0; j < COLS; j++){
//             printf("%d ", result[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// 1. Nearest Row Search

// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <pthread.h>

// typedef struct {
//     int rowIndex;
//     int cols;
//     double *row;
//     double *target;
//     double distance;
// } ThreadData;

// void* computeDistance(void *arg) {
//     ThreadData* data = (ThreadData*) arg;
//     double sum = 0.0;
//     for (int j = 0; j < data->cols; j++) {
//         double diff = data->row[j] - data->target[j];
//         sum += diff * diff;
//     }
//     data->distance = sqrt(sum);
//     pthread_exit(NULL);
// }

// typedef struct {
//     int index;
//     double distance;
// } DistanceInfo;

// int cmpDistance(const void *a, const void *b) {
//     DistanceInfo *da = (DistanceInfo*) a;
//     DistanceInfo *db = (DistanceInfo*) b;
//     if (da->distance < db->distance) return -1;
//     else if (da->distance > db->distance) return 1;
//     else return 0;
// }

// int main() {
//     FILE *fp = fopen("matrix.txt", "r");
//     if (!fp) { perror("Error opening matrix.txt"); exit(1); }
//     int rows, cols;
//     fscanf(fp, "%d %d", &rows, &cols);
    
//     double **matrix = malloc(rows * sizeof(double*));
//     for (int i = 0; i < rows; i++) {
//         matrix[i] = malloc(cols * sizeof(double));
//         for (int j = 0; j < cols; j++) {
//             fscanf(fp, "%lf", &matrix[i][j]);
//         }
//     }
//     fclose(fp);

//     fp = fopen("target.txt", "r");
//     if (!fp) { perror("Error opening target.txt"); exit(1); }
//     double *target = malloc(cols * sizeof(double));
//     for (int j = 0; j < cols; j++) {
//         fscanf(fp, "%lf", &target[j]);
//     }
//     fclose(fp);

//     pthread_t *threads = malloc(rows * sizeof(pthread_t));
//     ThreadData *tdata = malloc(rows * sizeof(ThreadData));
//     for (int i = 0; i < rows; i++) {
//         tdata[i].rowIndex = i;
//         tdata[i].cols = cols;
//         tdata[i].row = matrix[i];
//         tdata[i].target = target;
//         pthread_create(&threads[i], NULL, computeDistance, &tdata[i]);
//     }
//     for (int i = 0; i < rows; i++) {
//         pthread_join(threads[i], NULL);
//     }
    
//     DistanceInfo *dinfo = malloc(rows * sizeof(DistanceInfo));
//     for (int i = 0; i < rows; i++) {
//         dinfo[i].index = i;
//         dinfo[i].distance = tdata[i].distance;
//     }
//     qsort(dinfo, rows, sizeof(DistanceInfo), cmpDistance);
    
//     int k = (rows < 4) ? rows : 4;
//     printf("Four rows closest to the target:\n");
//     for (int i = 0; i < k; i++) {
//         int r = dinfo[i].index;
//         printf("Row %d (Distance = %lf): ", r, dinfo[i].distance);
//         for (int j = 0; j < cols; j++)
//             printf("%lf ", matrix[r][j]);
//         printf("\n");
//     }
    
//     // Cleanup
//     for (int i = 0; i < rows; i++) free(matrix[i]);
//     free(matrix); free(target); free(threads); free(tdata); free(dinfo);
//     return 0;
// }


// 2. Nearest Column Search

// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <pthread.h>

// typedef struct {
//     int colIndex;
//     int rows;
//     double **matrix;
//     double *target;
//     double distance;
// } ThreadData;

// void* computeColDistance(void *arg) {
//     ThreadData* data = (ThreadData*) arg;
//     double sum = 0.0;
//     for (int i = 0; i < data->rows; i++) {
//         double diff = data->matrix[i][data->colIndex] - data->target[i];
//         sum += diff * diff;
//     }
//     data->distance = sqrt(sum);
//     pthread_exit(NULL);
// }

// typedef struct {
//     int index;
//     double distance;
// } DistanceInfo;

// int cmpDistance(const void *a, const void *b) {
//     DistanceInfo *da = (DistanceInfo*) a;
//     DistanceInfo *db = (DistanceInfo*) b;
//     if (da->distance < db->distance) return -1;
//     else if (da->distance > db->distance) return 1;
//     else return 0;
// }

// int main() {
//     FILE *fp = fopen("matrix.txt", "r");
//     if (!fp) { perror("Error opening matrix.txt"); exit(1); }
//     int rows, cols;
//     fscanf(fp, "%d %d", &rows, &cols);
    
//     double **matrix = malloc(rows * sizeof(double*));
//     for (int i = 0; i < rows; i++) {
//         matrix[i] = malloc(cols * sizeof(double));
//         for (int j = 0; j < cols; j++) {
//             fscanf(fp, "%lf", &matrix[i][j]);
//         }
//     }
//     fclose(fp);

//     fp = fopen("target_col.txt", "r");
//     if (!fp) { perror("Error opening target_col.txt"); exit(1); }
//     double *target = malloc(rows * sizeof(double));
//     for (int i = 0; i < rows; i++) {
//         fscanf(fp, "%lf", &target[i]);
//     }
//     fclose(fp);

//     pthread_t *threads = malloc(cols * sizeof(pthread_t));
//     ThreadData *tdata = malloc(cols * sizeof(ThreadData));
//     for (int j = 0; j < cols; j++) {
//         tdata[j].colIndex = j;
//         tdata[j].rows = rows;
//         tdata[j].matrix = matrix;
//         tdata[j].target = target;
//         pthread_create(&threads[j], NULL, computeColDistance, &tdata[j]);
//     }
//     for (int j = 0; j < cols; j++) {
//         pthread_join(threads[j], NULL);
//     }
    
//     DistanceInfo *dinfo = malloc(cols * sizeof(DistanceInfo));
//     for (int j = 0; j < cols; j++) {
//         dinfo[j].index = j;
//         dinfo[j].distance = tdata[j].distance;
//     }
//     qsort(dinfo, cols, sizeof(DistanceInfo), cmpDistance);
    
//     int k = (cols < 4) ? cols : 4;
//     printf("Four columns closest to the target column:\n");
//     for (int i = 0; i < k; i++) {
//         int c = dinfo[i].index;
//         printf("Column %d (Distance = %lf): ", c, dinfo[i].distance);
//         for (int r = 0; r < rows; r++)
//             printf("%lf ", matrix[r][c]);
//         printf("\n");
//     }
    
//     // Cleanup
//     for (int i = 0; i < rows; i++) free(matrix[i]);
//     free(matrix); free(target); free(threads); free(tdata); free(dinfo);
//     return 0;
// }


// 3. Dot Product Maximizer

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// typedef struct {
//     int colIndex;
//     int rows;
//     double **matrix;
//     double *vector;
//     double dotProduct;
// } ThreadData;

// void* computeDotProduct(void *arg) {
//     ThreadData* data = (ThreadData*) arg;
//     double sum = 0.0;
//     for (int i = 0; i < data->rows; i++) {
//         sum += data->matrix[i][data->colIndex] * data->vector[i];
//     }
//     data->dotProduct = sum;
//     pthread_exit(NULL);
// }

// int main() {
//     FILE *fp = fopen("matrix.txt", "r");
//     if (!fp) { perror("Error opening matrix.txt"); exit(1); }
//     int rows, cols;
//     fscanf(fp, "%d %d", &rows, &cols);
    
//     double **matrix = malloc(rows * sizeof(double*));
//     for (int i = 0; i < rows; i++) {
//         matrix[i] = malloc(cols * sizeof(double));
//         for (int j = 0; j < cols; j++) {
//             fscanf(fp, "%lf", &matrix[i][j]);
//         }
//     }
//     fclose(fp);
    
//     fp = fopen("vector.txt", "r");
//     if (!fp) { perror("Error opening vector.txt"); exit(1); }
//     double *vector = malloc(rows * sizeof(double));
//     for (int i = 0; i < rows; i++) {
//         fscanf(fp, "%lf", &vector[i]);
//     }
//     fclose(fp);
    
//     pthread_t *threads = malloc(cols * sizeof(pthread_t));
//     ThreadData *tdata = malloc(cols * sizeof(ThreadData));
//     for (int j = 0; j < cols; j++) {
//         tdata[j].colIndex = j;
//         tdata[j].rows = rows;
//         tdata[j].matrix = matrix;
//         tdata[j].vector = vector;
//         pthread_create(&threads[j], NULL, computeDotProduct, &tdata[j]);
//     }
//     for (int j = 0; j < cols; j++) {
//         pthread_join(threads[j], NULL);
//     }
    
//     int bestCol = 0;
//     double maxDot = tdata[0].dotProduct;
//     for (int j = 1; j < cols; j++) {
//         if (tdata[j].dotProduct > maxDot) {
//             maxDot = tdata[j].dotProduct;
//             bestCol = j;
//         }
//     }
//     printf("Column with highest dot product: %d (Dot Product = %lf)\n", bestCol, maxDot);
    
//     // Cleanup
//     for (int i = 0; i < rows; i++) free(matrix[i]);
//     free(matrix); free(vector); free(threads); free(tdata);
//     return 0;
// }


// 4. Batch Matrix Inversion

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// #define MAX_SIZE 10

// typedef struct {
//     int id;
//     int n;
//     double A[MAX_SIZE][MAX_SIZE];
// } MatrixData;

// typedef struct {
//     MatrixData matrix;
//     int invertible;
// } ThreadResult;

// void* invertMatrix(void *arg) {
//     ThreadResult *result = (ThreadResult*) arg;
//     int n = result->matrix.n;
//     double augmented[MAX_SIZE][2*MAX_SIZE];
    
//     // Build augmented matrix [A | I]
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++)
//             augmented[i][j] = result->matrix.A[i][j];
//         for (int j = n; j < 2*n; j++)
//             augmented[i][j] = (i == (j - n)) ? 1.0 : 0.0;
//     }
    
//     result->invertible = 1;
//     // Gauss-Jordan elimination
//     for (int i = 0; i < n; i++) {
//         double pivot = augmented[i][i];
//         if (pivot == 0) { result->invertible = 0; pthread_exit(NULL); }
//         for (int j = 0; j < 2*n; j++)
//             augmented[i][j] /= pivot;
//         for (int k = 0; k < n; k++) {
//             if (k != i) {
//                 double factor = augmented[k][i];
//                 for (int j = 0; j < 2*n; j++)
//                     augmented[k][j] -= factor * augmented[i][j];
//             }
//         }
//     }
    
//     if (result->invertible) {
//         printf("Matrix ID %d Inverse:\n", result->matrix.id);
//         for (int i = 0; i < n; i++) {
//             for (int j = n; j < 2*n; j++) {
//                 printf("%8.4lf ", augmented[i][j]);
//             }
//             printf("\n");
//         }
//     } else {
//         printf("Matrix ID %d is not invertible.\n", result->matrix.id);
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     FILE *fp = fopen("matrices.txt", "r");
//     if (!fp) { perror("Error opening matrices.txt"); exit(1); }
//     int count;
//     fscanf(fp, "%d", &count);
    
//     ThreadResult *results = malloc(count * sizeof(ThreadResult));
//     pthread_t *threads = malloc(count * sizeof(pthread_t));
    
//     for (int m = 0; m < count; m++) {
//         results[m].matrix.id = m;
//         fscanf(fp, "%d", &results[m].matrix.n);
//         int n = results[m].matrix.n;
//         for (int i = 0; i < n; i++)
//             for (int j = 0; j < n; j++)
//                 fscanf(fp, "%lf", &results[m].matrix.A[i][j]);
//         pthread_create(&threads[m], NULL, invertMatrix, &results[m]);
//     }
//     fclose(fp);
    
//     for (int m = 0; m < count; m++) {
//         pthread_join(threads[m], NULL);
//     }
    
//     free(results);
//     free(threads);
//     return 0;
// }


// 5. Global Sum Calculation

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// typedef struct {
//     int startRow, endRow;
//     int cols;
//     double **matrix;
//     double partialSum;
// } ThreadData;

// void* computeSegmentSum(void *arg) {
//     ThreadData *data = (ThreadData*) arg;
//     double sum = 0.0;
//     for (int i = data->startRow; i < data->endRow; i++) {
//         for (int j = 0; j < data->cols; j++) {
//             sum += data->matrix[i][j];
//         }
//     }
//     data->partialSum = sum;
//     pthread_exit(NULL);
// }

// int main() {
//     FILE *fp = fopen("large_matrix.txt", "r");
//     if (!fp) { perror("Error opening large_matrix.txt"); exit(1); }
//     int rows, cols;
//     fscanf(fp, "%d %d", &rows, &cols);
    
//     double **matrix = malloc(rows * sizeof(double*));
//     for (int i = 0; i < rows; i++) {
//         matrix[i] = malloc(cols * sizeof(double));
//         for (int j = 0; j < cols; j++) {
//             fscanf(fp, "%lf", &matrix[i][j]);
//         }
//     }
//     fclose(fp);
    
//     int numThreads = 4;  // or adjust based on your system
//     pthread_t threads[numThreads];
//     ThreadData tdata[numThreads];
//     int rowsPerThread = rows / numThreads;
    
//     for (int t = 0; t < numThreads; t++) {
//         tdata[t].startRow = t * rowsPerThread;
//         tdata[t].endRow = (t == numThreads - 1) ? rows : (t + 1) * rowsPerThread;
//         tdata[t].cols = cols;
//         tdata[t].matrix = matrix;
//         pthread_create(&threads[t], NULL, computeSegmentSum, &tdata[t]);
//     }
    
//     double totalSum = 0.0;
//     for (int t = 0; t < numThreads; t++) {
//         pthread_join(threads[t], NULL);
//         totalSum += tdata[t].partialSum;
//     }
//     printf("Total sum of matrix elements: %lf\n", totalSum);
    
//     for (int i = 0; i < rows; i++) free(matrix[i]);
//     free(matrix);
//     return 0;
// }

// 6. Sliding Window Determinant

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// typedef struct {
//     int startRow, startCol;
//     double window[3][3];
//     double determinant;
// } ThreadData;

// // Compute determinant of a 3x3 matrix
// double det3x3(double m[3][3]) {
//     return m[0][0]*(m[1][1]*m[2][2]-m[1][2]*m[2][1]) -
//            m[0][1]*(m[1][0]*m[2][2]-m[1][2]*m[2][0]) +
//            m[0][2]*(m[1][0]*m[2][1]-m[1][1]*m[2][0]);
// }

// void* computeWindowDet(void *arg) {
//     ThreadData *data = (ThreadData*) arg;
//     data->determinant = det3x3(data->window);
//     pthread_exit(NULL);
// }

// int main() {
//     FILE *fp = fopen("large_matrix.txt", "r");
//     if (!fp) { perror("Error opening large_matrix.txt"); exit(1); }
//     int rows, cols;
//     fscanf(fp, "%d %d", &rows, &cols);
//     double **matrix = malloc(rows * sizeof(double*));
//     for (int i = 0; i < rows; i++){
//         matrix[i] = malloc(cols * sizeof(double));
//         for (int j = 0; j < cols; j++){
//             fscanf(fp, "%lf", &matrix[i][j]);
//         }
//     }
//     fclose(fp);
    
//     int winSize = 3;
//     int numWindows = (rows - winSize + 1) * (cols - winSize + 1);
//     ThreadData *tdata = malloc(numWindows * sizeof(ThreadData));
//     pthread_t *threads = malloc(numWindows * sizeof(pthread_t));
    
//     int index = 0;
//     for (int i = 0; i <= rows - winSize; i++) {
//         for (int j = 0; j <= cols - winSize; j++) {
//             tdata[index].startRow = i;
//             tdata[index].startCol = j;
//             // Copy the submatrix into the window
//             for (int r = 0; r < winSize; r++) {
//                 for (int c = 0; c < winSize; c++) {
//                     tdata[index].window[r][c] = matrix[i+r][j+c];
//                 }
//             }
//             pthread_create(&threads[index], NULL, computeWindowDet, &tdata[index]);
//             index++;
//         }
//     }
    
//     // Wait for all threads and print determinants
//     for (int i = 0; i < numWindows; i++) {
//         pthread_join(threads[i], NULL);
//         printf("Window at (%d,%d) determinant: %lf\n", tdata[i].startRow, tdata[i].startCol, tdata[i].determinant);
//     }
    
//     for (int i = 0; i < rows; i++) free(matrix[i]);
//     free(matrix); free(tdata); free(threads);
//     return 0;
// }


// 7. Self-Multiplication Check

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <stdbool.h>

// typedef struct {
//     int row;
//     int n;
//     double **matrix;
//     double **result;
// } ThreadData;

// void* multiplyRow(void *arg) {
//     ThreadData *data = (ThreadData*) arg;
//     int n = data->n;
//     int r = data->row;
//     for (int j = 0; j < n; j++) {
//         data->result[r][j] = 0.0;
//         for (int k = 0; k < n; k++) {
//             data->result[r][j] += data->matrix[r][k] * data->matrix[j][k]; // Note: using transpose means A*A^T
//         }
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     FILE *fp = fopen("matrix.txt", "r");
//     if (!fp) { perror("Error opening matrix.txt"); exit(1); }
//     int n;
//     fscanf(fp, "%d", &n);
    
//     double **matrix = malloc(n * sizeof(double*));
//     for (int i = 0; i < n; i++){
//         matrix[i] = malloc(n * sizeof(double));
//         for (int j = 0; j < n; j++){
//             fscanf(fp, "%lf", &matrix[i][j]);
//         }
//     }
//     fclose(fp);
    
//     // Allocate result matrix
//     double **result = malloc(n * sizeof(double*));
//     for (int i = 0; i < n; i++){
//         result[i] = calloc(n, sizeof(double));
//     }
    
//     pthread_t *threads = malloc(n * sizeof(pthread_t));
//     ThreadData *tdata = malloc(n * sizeof(ThreadData));
//     for (int i = 0; i < n; i++) {
//         tdata[i].row = i;
//         tdata[i].n = n;
//         tdata[i].matrix = matrix;
//         tdata[i].result = result;
//         pthread_create(&threads[i], NULL, multiplyRow, &tdata[i]);
//     }
//     for (int i = 0; i < n; i++){
//         pthread_join(threads[i], NULL);
//     }
    
//     bool symmetric = true;
//     for (int i = 0; i < n && symmetric; i++){
//         for (int j = 0; j < n; j++){
//             if (fabs(result[i][j] - result[j][i]) > 1e-6) {
//                 symmetric = false;
//                 printf("Discrepancy at (%d,%d): %lf vs %lf\n", i, j, result[i][j], result[j][i]);
//             }
//         }
//     }
//     if (symmetric)
//         printf("The result matrix is symmetric.\n");
    
//     for (int i = 0; i < n; i++){
//         free(matrix[i]); free(result[i]);
//     }
//     free(matrix); free(result); free(threads); free(tdata);
//     return 0;
// }


// 8. Inverse Verification

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <math.h>

// typedef struct {
//     int row;
//     int n;
//     double **A;
//     double **B;
//     double **product;
// } ThreadData;

// void* multiplyRow(void *arg) {
//     ThreadData *data = (ThreadData*) arg;
//     int n = data->n;
//     int i = data->row;
//     for (int j = 0; j < n; j++){
//         data->product[i][j] = 0.0;
//         for (int k = 0; k < n; k++){
//             data->product[i][j] += data->A[i][k] * data->B[k][j];
//         }
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     FILE *fp = fopen("matrix.txt", "r");
//     if (!fp) { perror("Error opening matrix.txt"); exit(1); }
//     int n;
//     fscanf(fp, "%d", &n);
//     double **A = malloc(n * sizeof(double*));
//     for (int i = 0; i < n; i++){
//         A[i] = malloc(n * sizeof(double));
//         for (int j = 0; j < n; j++){
//             fscanf(fp, "%lf", &A[i][j]);
//         }
//     }
//     fclose(fp);
    
//     fp = fopen("inverse.txt", "r");
//     if (!fp) { perror("Error opening inverse.txt"); exit(1); }
//     int n2;
//     fscanf(fp, "%d", &n2);
//     if(n2 != n) { printf("Matrix dimensions do not match!\n"); exit(1); }
//     double **B = malloc(n * sizeof(double*));
//     for (int i = 0; i < n; i++){
//         B[i] = malloc(n * sizeof(double));
//         for (int j = 0; j < n; j++){
//             fscanf(fp, "%lf", &B[i][j]);
//         }
//     }
//     fclose(fp);
    
//     double **product = malloc(n * sizeof(double*));
//     for (int i = 0; i < n; i++){
//         product[i] = calloc(n, sizeof(double));
//     }
    
//     pthread_t *threads = malloc(n * sizeof(pthread_t));
//     ThreadData *tdata = malloc(n * sizeof(ThreadData));
//     for (int i = 0; i < n; i++){
//         tdata[i].row = i;
//         tdata[i].n = n;
//         tdata[i].A = A;
//         tdata[i].B = B;
//         tdata[i].product = product;
//         pthread_create(&threads[i], NULL, multiplyRow, &tdata[i]);
//     }
//     for (int i = 0; i < n; i++){
//         pthread_join(threads[i], NULL);
//     }
    
//     // Check against identity matrix
//     int ok = 1;
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < n; j++){
//             double expected = (i == j) ? 1.0 : 0.0;
//             if (fabs(product[i][j] - expected) > 1e-6) {
//                 printf("Mismatch at (%d,%d): %lf vs %lf\n", i, j, product[i][j], expected);
//                 ok = 0;
//             }
//         }
//     }
//     if (ok)
//         printf("The product is the identity matrix. Verification successful.\n");
//     else
//         printf("The matrices are not inverses.\n");
    
//     for (int i = 0; i < n; i++){
//         free(A[i]); free(B[i]); free(product[i]);
//     }
//     free(A); free(B); free(product); free(threads); free(tdata);
//     return 0;
// }


// 9. Target Row Sum Match

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <math.h>

// typedef struct {
//     int rowIndex;
//     int cols;
//     double *row;
//     double sum;
// } ThreadData;

// void* computeRowSum(void *arg) {
//     ThreadData *data = (ThreadData*) arg;
//     double sum = 0.0;
//     for (int j = 0; j < data->cols; j++){
//         sum += data->row[j];
//     }
//     data->sum = sum;
//     pthread_exit(NULL);
// }

// int main() {
//     FILE *fp = fopen("matrix.txt", "r");
//     if (!fp) { perror("Error opening matrix.txt"); exit(1); }
//     int rows, cols;
//     fscanf(fp, "%d %d", &rows, &cols);
//     double **matrix = malloc(rows * sizeof(double*));
//     for (int i = 0; i < rows; i++){
//         matrix[i] = malloc(cols * sizeof(double));
//         for (int j = 0; j < cols; j++){
//             fscanf(fp, "%lf", &matrix[i][j]);
//         }
//     }
//     fclose(fp);
    
//     fp = fopen("target_sum.txt", "r");
//     if (!fp) { perror("Error opening target_sum.txt"); exit(1); }
//     double target;
//     fscanf(fp, "%lf", &target);
//     fclose(fp);
    
//     pthread_t *threads = malloc(rows * sizeof(pthread_t));
//     ThreadData *tdata = malloc(rows * sizeof(ThreadData));
//     for (int i = 0; i < rows; i++){
//         tdata[i].rowIndex = i;
//         tdata[i].cols = cols;
//         tdata[i].row = matrix[i];
//         pthread_create(&threads[i], NULL, computeRowSum, &tdata[i]);
//     }
//     for (int i = 0; i < rows; i++){
//         pthread_join(threads[i], NULL);
//     }
    
//     int bestIndex = 0;
//     double bestDiff = fabs(tdata[0].sum - target);
//     for (int i = 1; i < rows; i++){
//         double diff = fabs(tdata[i].sum - target);
//         if (diff < bestDiff) {
//             bestDiff = diff;
//             bestIndex = i;
//         }
//     }
//     printf("Row with sum closest to target %lf: Row %d with sum %lf\n", target, bestIndex, tdata[bestIndex].sum);
    
//     for (int i = 0; i < rows; i++){
//         free(matrix[i]);
//     }
//     free(matrix); free(threads); free(tdata);
//     return 0;
// }


// 1. Scalar–Matrix Combination

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// typedef struct {
//     int rows, cols;
//     double **matrix;
//     double scalar;
//     double **scaled; // output scaled matrix
// } ScaleData;

// typedef struct {
//     int rows, cols;
//     double **matrix;
//     double trace;  // output trace value
// } TraceData;

// void* scaleMatrix(void *arg) {
//     ScaleData *data = (ScaleData*) arg;
//     for (int i = 0; i < data->rows; i++) {
//         for (int j = 0; j < data->cols; j++) {
//             data->scaled[i][j] = data->matrix[i][j] * data->scalar;
//         }
//     }
//     pthread_exit(NULL);
// }

// void* computeTrace(void *arg) {
//     TraceData *data = (TraceData*) arg;
//     double sum = 0.0;
//     int n = data->rows < data->cols ? data->rows : data->cols;
//     for (int i = 0; i < n; i++) {
//         sum += data->matrix[i][i];
//     }
//     data->trace = sum;
//     pthread_exit(NULL);
// }

// int main() {
//     FILE *fp = fopen("matrix.txt", "r");
//     if (!fp) { perror("Error opening matrix.txt"); exit(1); }
//     int rows, cols;
//     fscanf(fp, "%d %d", &rows, &cols);
    
//     double **matrix = malloc(rows * sizeof(double*));
//     for (int i = 0; i < rows; i++){
//         matrix[i] = malloc(cols * sizeof(double));
//         for (int j = 0; j < cols; j++){
//             fscanf(fp, "%lf", &matrix[i][j]);
//         }
//     }
//     fclose(fp);
    
//     // For demonstration, we use a fixed scalar.
//     double scalar = 2.5;
    
//     // Allocate memory for scaled matrix
//     double **scaled = malloc(rows * sizeof(double*));
//     for (int i = 0; i < rows; i++){
//         scaled[i] = malloc(cols * sizeof(double));
//     }
    
//     ScaleData sData = {rows, cols, matrix, scalar, scaled};
//     TraceData tData = {rows, cols, matrix, 0.0};
    
//     pthread_t thread1, thread2;
//     pthread_create(&thread1, NULL, scaleMatrix, &sData);
//     pthread_create(&thread2, NULL, computeTrace, &tData);
    
//     pthread_join(thread1, NULL);
//     pthread_join(thread2, NULL);
    
//     printf("Scaled Matrix (each element multiplied by %.2lf):\n", scalar);
//     for (int i = 0; i < rows; i++){
//         for (int j = 0; j < cols; j++){
//             printf("%6.2lf ", scaled[i][j]);
//         }
//         printf("\n");
//     }
//     printf("Trace of the matrix: %.2lf\n", tData.trace);
    
//     // Cleanup
//     for (int i = 0; i < rows; i++){
//         free(matrix[i]);
//         free(scaled[i]);
//     }
//     free(matrix); free(scaled);
//     return 0;
// }

// 2. Trace and Diagonal Difference

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <math.h>

// typedef struct {
//     int n;           // square matrix of size n x n
//     double **matrix;
//     double trace;
// } TraceTask;

// typedef struct {
//     int n;
//     double **matrix;
//     double anti;
// } AntiDiagTask;

// void* computeTrace(void *arg) {
//     TraceTask *task = (TraceTask*) arg;
//     double sum = 0.0;
//     for (int i = 0; i < task->n; i++) {
//         sum += task->matrix[i][i];
//     }
//     task->trace = sum;
//     pthread_exit(NULL);
// }

// void* computeAntiDiag(void *arg) {
//     AntiDiagTask *task = (AntiDiagTask*) arg;
//     double sum = 0.0;
//     for (int i = 0; i < task->n; i++) {
//         sum += task->matrix[i][task->n - i - 1];
//     }
//     task->anti = sum;
//     pthread_exit(NULL);
// }

// int main() {
//     FILE *fp = fopen("matrix.txt", "r");
//     if (!fp) { perror("Error opening matrix.txt"); exit(1); }
//     int n, dummy;
//     fscanf(fp, "%d %d", &n, &dummy);  // assuming square matrix; ignore second value if provided
//     double **matrix = malloc(n * sizeof(double*));
//     for (int i = 0; i < n; i++){
//         matrix[i] = malloc(n * sizeof(double));
//         for (int j = 0; j < n; j++){
//             fscanf(fp, "%lf", &matrix[i][j]);
//         }
//     }
//     fclose(fp);
    
//     TraceTask tTask = {n, matrix, 0.0};
//     AntiDiagTask aTask = {n, matrix, 0.0};
    
//     pthread_t thread1, thread2;
//     pthread_create(&thread1, NULL, computeTrace, &tTask);
//     pthread_create(&thread2, NULL, computeAntiDiag, &aTask);
    
//     pthread_join(thread1, NULL);
//     pthread_join(thread2, NULL);
    
//     double diff = fabs(tTask.trace - aTask.anti);
//     printf("Trace = %.2lf, Anti-diagonal sum = %.2lf, Absolute difference = %.2lf\n",
//            tTask.trace, aTask.anti, diff);
    
//     for (int i = 0; i < n; i++){
//         free(matrix[i]);
//     }
//     free(matrix);
//     return 0;
// }


// 3. LU Decomposition and Determinant

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// typedef struct {
//     int n;
//     double **U;
//     double diagProd; // product of diagonal elements
// } DiagTask;

// void* computeDiagProduct(void *arg) {
//     DiagTask *task = (DiagTask*) arg;
//     double prod = 1.0;
//     for (int i = 0; i < task->n; i++){
//         prod *= task->U[i][i];
//     }
//     task->diagProd = prod;
//     pthread_exit(NULL);
// }

// int main() {
//     FILE *fp = fopen("matrix.txt", "r");
//     if (!fp) { perror("Error opening matrix.txt"); exit(1); }
//     int n, dummy;
//     fscanf(fp, "%d %d", &n, &dummy);
//     double **A = malloc(n * sizeof(double*));
//     for (int i = 0; i < n; i++){
//         A[i] = malloc(n * sizeof(double));
//         for (int j = 0; j < n; j++){
//             fscanf(fp, "%lf", &A[i][j]);
//         }
//     }
//     fclose(fp);
    
//     // Allocate L and U matrices for LU decomposition (using Doolittle's method)
//     double **L = malloc(n * sizeof(double*));
//     double **U = malloc(n * sizeof(double*));
//     for (int i = 0; i < n; i++){
//         L[i] = calloc(n, sizeof(double));
//         U[i] = calloc(n, sizeof(double));
//     }
    
//     // Doolittle's method: L[i][i]=1 and U computed sequentially.
//     for (int i = 0; i < n; i++) {
//         L[i][i] = 1.0;
//         for (int j = i; j < n; j++) {
//             double sum = 0.0;
//             for (int k = 0; k < i; k++)
//                 sum += L[i][k] * U[k][j];
//             U[i][j] = A[i][j] - sum;
//         }
//         for (int j = i+1; j < n; j++) {
//             double sum = 0.0;
//             for (int k = 0; k < i; k++)
//                 sum += L[j][k] * U[k][i];
//             L[j][i] = (A[j][i] - sum) / U[i][i];
//         }
//     }
    
//     // For demonstration, we only need U's diagonal to compute determinant.
//     DiagTask dTask = {n, U, 0.0};
//     pthread_t thread;
//     pthread_create(&thread, NULL, computeDiagProduct, &dTask);
//     pthread_join(thread, NULL);
    
//     printf("Determinant (product of U's diagonal): %.6lf\n", dTask.diagProd);
    
//     // Cleanup
//     for (int i = 0; i < n; i++){
//         free(A[i]); free(L[i]); free(U[i]);
//     }
//     free(A); free(L); free(U);
//     return 0;
// }


// 4. Parallel Gaussian Elimination

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// typedef struct {
//     int pivot;
//     int row;
//     int n;
//     double **mat;
// } ElimTask;

// void* eliminate(void *arg) {
//     ElimTask *task = (ElimTask*) arg;
//     int n = task->n;
//     int p = task->pivot, i = task->row;
//     double factor = task->mat[i][p] / task->mat[p][p];
//     for (int j = p; j < n+1; j++) {
//         task->mat[i][j] -= factor * task->mat[p][j];
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     FILE *fp = fopen("system.txt", "r");
//     if (!fp) { perror("Error opening system.txt"); exit(1); }
//     int n;
//     fscanf(fp, "%d", &n);
    
//     // Allocate augmented matrix (n x (n+1))
//     double **mat = malloc(n * sizeof(double*));
//     for (int i = 0; i < n; i++){
//         mat[i] = malloc((n+1) * sizeof(double));
//         for (int j = 0; j < n+1; j++){
//             fscanf(fp, "%lf", &mat[i][j]);
//         }
//     }
//     fclose(fp);
    
//     // Gaussian elimination with multithreading for row elimination.
//     for (int p = 0; p < n-1; p++) {
//         int numThreads = n - p - 1;
//         pthread_t *threads = malloc(numThreads * sizeof(pthread_t));
//         ElimTask *tasks = malloc(numThreads * sizeof(ElimTask));
//         for (int i = p+1, t = 0; i < n; i++, t++) {
//             tasks[t].pivot = p;
//             tasks[t].row = i;
//             tasks[t].n = n;
//             tasks[t].mat = mat;
//             pthread_create(&threads[t], NULL, eliminate, &tasks[t]);
//         }
//         for (int t = 0; t < numThreads; t++){
//             pthread_join(threads[t], NULL);
//         }
//         free(threads);
//         free(tasks);
//     }
    
//     // Back substitution to solve for variables
//     double *x = malloc(n * sizeof(double));
//     for (int i = n-1; i >= 0; i--){
//         x[i] = mat[i][n];
//         for (int j = i+1; j < n; j++){
//             x[i] -= mat[i][j] * x[j];
//         }
//         x[i] /= mat[i][i];
//     }
    
//     printf("Solution of the system:\n");
//     for (int i = 0; i < n; i++){
//         printf("x%d = %lf\n", i, x[i]);
//     }
    
//     for (int i = 0; i < n; i++){
//         free(mat[i]);
//     }
//     free(mat); free(x);
//     return 0;
// }


// 5. Inverse Verification with Residual

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <math.h>

// typedef struct {
//     int start, end; // rows to process
//     int n;
//     double **A;
//     double **B;
//     double **product; // result of A * B
// } ProdTask;

// void* computeProduct(void *arg) {
//     ProdTask *task = (ProdTask*) arg;
//     int n = task->n;
//     for (int i = task->start; i < task->end; i++) {
//         for (int j = 0; j < n; j++){
//             task->product[i][j] = 0.0;
//             for (int k = 0; k < n; k++){
//                 task->product[i][j] += task->A[i][k] * task->B[k][j];
//             }
//         }
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     FILE *fp = fopen("matrix.txt", "r");
//     if (!fp) { perror("Error opening matrix.txt"); exit(1); }
//     int n, dummy;
//     fscanf(fp, "%d %d", &n, &dummy);
//     double **A = malloc(n * sizeof(double*));
//     for (int i = 0; i < n; i++){
//         A[i] = malloc(n * sizeof(double));
//         for (int j = 0; j < n; j++){
//             fscanf(fp, "%lf", &A[i][j]);
//         }
//     }
//     fclose(fp);
    
//     fp = fopen("inverse.txt", "r");
//     if (!fp) { perror("Error opening inverse.txt"); exit(1); }
//     int n2, dummy2;
//     fscanf(fp, "%d %d", &n2, &dummy2);
//     if(n != n2) { printf("Dimension mismatch!\n"); exit(1); }
//     double **B = malloc(n * sizeof(double*));
//     for (int i = 0; i < n; i++){
//         B[i] = malloc(n * sizeof(double));
//         for (int j = 0; j < n; j++){
//             fscanf(fp, "%lf", &B[i][j]);
//         }
//     }
//     fclose(fp);
    
//     // Allocate product matrix
//     double **product = malloc(n * sizeof(double*));
//     for (int i = 0; i < n; i++){
//         product[i] = calloc(n, sizeof(double));
//     }
    
//     int numThreads = 4; // adjust as needed
//     pthread_t threads[numThreads];
//     ProdTask tasks[numThreads];
//     int rowsPerThread = n / numThreads;
//     for (int t = 0; t < numThreads; t++){
//         tasks[t].start = t * rowsPerThread;
//         tasks[t].end = (t == numThreads - 1) ? n : (t+1) * rowsPerThread;
//         tasks[t].n = n;
//         tasks[t].A = A;
//         tasks[t].B = B;
//         tasks[t].product = product;
//         pthread_create(&threads[t], NULL, computeProduct, &tasks[t]);
//     }
//     for (int t = 0; t < numThreads; t++){
//         pthread_join(threads[t], NULL);
//     }
    
//     // Compute residual error = ||product - I|| (Frobenius norm)
//     double residual = 0.0;
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < n; j++){
//             double expected = (i == j) ? 1.0 : 0.0;
//             double diff = product[i][j] - expected;
//             residual += diff * diff;
//         }
//     }
//     residual = sqrt(residual);
//     printf("Residual error (Frobenius norm): %lf\n", residual);
    
//     // Cleanup
//     for (int i = 0; i < n; i++){
//         free(A[i]); free(B[i]); free(product[i]);
//     }
//     free(A); free(B); free(product);
//     return 0;
// }


// 6. Matrix–Vector Product and Norm

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <math.h>

// typedef struct {
//     int row;
//     int cols;
//     double **matrix;
//     double *vector;
//     double result;  // dot product result for that row
// } MVTask;

// void* computeRowProduct(void *arg) {
//     MVTask *task = (MVTask*) arg;
//     double sum = 0.0;
//     for (int j = 0; j < task->cols; j++){
//         sum += task->matrix[task->row][j] * task->vector[j];
//     }
//     task->result = sum;
//     pthread_exit(NULL);
// }

// int main() {
//     FILE *fp = fopen("matrix.txt", "r");
//     if (!fp) { perror("Error opening matrix.txt"); exit(1); }
//     int rows, cols;
//     fscanf(fp, "%d %d", &rows, &cols);
//     double **matrix = malloc(rows * sizeof(double*));
//     for (int i = 0; i < rows; i++){
//         matrix[i] = malloc(cols * sizeof(double));
//         for (int j = 0; j < cols; j++){
//             fscanf(fp, "%lf", &matrix[i][j]);
//         }
//     }
//     fclose(fp);
    
//     fp = fopen("vector.txt", "r");
//     if (!fp) { perror("Error opening vector.txt"); exit(1); }
//     double *vector = malloc(cols * sizeof(double));
//     for (int j = 0; j < cols; j++){
//         fscanf(fp, "%lf", &vector[j]);
//     }
//     fclose(fp);
    
//     MVTask *tasks = malloc(rows * sizeof(MVTask));
//     pthread_t *threads = malloc(rows * sizeof(pthread_t));
//     for (int i = 0; i < rows; i++){
//         tasks[i].row = i;
//         tasks[i].cols = cols;
//         tasks[i].matrix = matrix;
//         tasks[i].vector = vector;
//         pthread_create(&threads[i], NULL, computeRowProduct, &tasks[i]);
//     }
//     double *resultVec = malloc(rows * sizeof(double));
//     for (int i = 0; i < rows; i++){
//         pthread_join(threads[i], NULL);
//         resultVec[i] = tasks[i].result;
//     }
    
//     double norm = 0.0;
//     for (int i = 0; i < rows; i++){
//         norm += resultVec[i] * resultVec[i];
//     }
//     norm = sqrt(norm);
    
//     printf("Matrix-vector product (result vector):\n");
//     for (int i = 0; i < rows; i++){
//         printf("%lf ", resultVec[i]);
//     }
//     printf("\nEuclidean norm of the result vector: %lf\n", norm);
    
//     // Cleanup
//     for (int i = 0; i < rows; i++){
//         free(matrix[i]);
//     }
//     free(matrix); free(vector); free(tasks); free(threads); free(resultVec);
//     return 0;
// }


// 7. Block Determinant Computation

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// typedef struct {
//     double block[2][2];
//     double det;
// } BlockTask;

// double compute2x2Det(double mat[2][2]) {
//     return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
// }

// void* computeBlockDet(void *arg) {
//     BlockTask *task = (BlockTask*) arg;
//     task->det = compute2x2Det(task->block);
//     pthread_exit(NULL);
// }

// int main() {
//     FILE *fp = fopen("matrix.txt", "r");
//     if (!fp) { perror("Error opening matrix.txt"); exit(1); }
//     int n, dummy;
//     fscanf(fp, "%d %d", &n, &dummy);
//     if(n != 4) {
//         printf("This example assumes a 4x4 matrix.\n");
//         exit(1);
//     }
//     double mat[4][4];
//     for (int i = 0; i < 4; i++){
//         for (int j = 0; j < 4; j++){
//             fscanf(fp, "%lf", &mat[i][j]);
//         }
//     }
//     fclose(fp);
    
//     // Partition into 2x2 blocks:
//     // A: top-left, B: top-right, C: bottom-left, D: bottom-right
//     BlockTask A = {{{mat[0][0], mat[0][1]}, {mat[1][0], mat[1][1]}}, 0.0};
//     BlockTask B = {{{mat[0][2], mat[0][3]}, {mat[1][2], mat[1][3]}}, 0.0};
//     BlockTask C = {{{mat[2][0], mat[2][1]}, {mat[3][0], mat[3][1]}}, 0.0};
//     BlockTask D = {{{mat[2][2], mat[2][3]}, {mat[3][2], mat[3][3]}}, 0.0};
    
//     pthread_t tA, tB, tC, tD;
//     pthread_create(&tA, NULL, computeBlockDet, &A);
//     pthread_create(&tB, NULL, computeBlockDet, &B);
//     pthread_create(&tC, NULL, computeBlockDet, &C);
//     pthread_create(&tD, NULL, computeBlockDet, &D);
    
//     pthread_join(tA, NULL);
//     pthread_join(tB, NULL);
//     pthread_join(tC, NULL);
//     pthread_join(tD, NULL);
    
//     double det = A.det * D.det - B.det * C.det;
//     printf("Block determinants: A=%.2lf, B=%.2lf, C=%.2lf, D=%.2lf\n", A.det, B.det, C.det, D.det);
//     printf("Overall determinant (using block formula): %.2lf\n", det);
//     return 0;
// }


// 8. Row Cumulative Sum

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// typedef struct {
//     int row;
//     int cols;
//     double *data;
//     double sum;
//     double average;
// } RowTask;

// void* computeRowSum(void *arg) {
//     RowTask *task = (RowTask*) arg;
//     double sum = 0.0;
//     for (int j = 0; j < task->cols; j++){
//         sum += task->data[j];
//     }
//     task->sum = sum;
//     task->average = sum / task->cols;
//     pthread_exit(NULL);
// }

// int main() {
//     FILE *fp = fopen("matrix.txt", "r");
//     if (!fp) { perror("Error opening matrix.txt"); exit(1); }
//     int rows, cols;
//     fscanf(fp, "%d %d", &rows, &cols);
    
//     double **matrix = malloc(rows * sizeof(double*));
//     for (int i = 0; i < rows; i++){
//         matrix[i] = malloc(cols * sizeof(double));
//         for (int j = 0; j < cols; j++){
//             fscanf(fp, "%lf", &matrix[i][j]);
//         }
//     }
//     fclose(fp);
    
//     RowTask *tasks = malloc(rows * sizeof(RowTask));
//     pthread_t *threads = malloc(rows * sizeof(pthread_t));
//     for (int i = 0; i < rows; i++){
//         tasks[i].row = i;
//         tasks[i].cols = cols;
//         tasks[i].data = matrix[i];
//         pthread_create(&threads[i], NULL, computeRowSum, &tasks[i]);
//     }
//     for (int i = 0; i < rows; i++){
//         pthread_join(threads[i], NULL);
//         printf("Row %d: Cumulative Sum = %.2lf, Average = %.2lf\n",
//                i, tasks[i].sum, tasks[i].average);
//     }
    
//     for (int i = 0; i < rows; i++){
//         free(matrix[i]);
//     }
//     free(matrix); free(tasks); free(threads);
//     return 0;
// }

// 9. Matrix Product and Element-wise Operations

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// #define THRESHOLD 10.0

// typedef struct {
//     int startRow, endRow;
//     int Arows, Acols, Bcols;
//     double **A;
//     double **B;
//     double **product;
// } ProdTask;

// typedef struct {
//     int startRow, endRow;
//     int rows, cols;
//     double threshold;
//     double **matrix;
// } ThresholdTask;

// void* multiplyRows(void *arg) {
//     ProdTask *task = (ProdTask*) arg;
//     for (int i = task->startRow; i < task->endRow; i++){
//         for (int j = 0; j < task->Bcols; j++){
//             task->product[i][j] = 0.0;
//             for (int k = 0; k < task->Acols; k++){
//                 task->product[i][j] += task->A[i][k] * task->B[k][j];
//             }
//         }
//     }
//     pthread_exit(NULL);
// }

// void* applyThreshold(void *arg) {
//     ThresholdTask *task = (ThresholdTask*) arg;
//     for (int i = task->startRow; i < task->endRow; i++){
//         for (int j = 0; j < task->cols; j++){
//             task->matrix[i][j] = (task->matrix[i][j] >= task->threshold) ? 1.0 : 0.0;
//         }
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     // Read first matrix A from "A.txt"
//     FILE *fp = fopen("A.txt", "r");
//     if (!fp) { perror("Error opening A.txt"); exit(1); }
//     int Arows, Acols;
//     fscanf(fp, "%d %d", &Arows, &Acols);
//     double **A = malloc(Arows * sizeof(double*));
//     for (int i = 0; i < Arows; i++){
//         A[i] = malloc(Acols * sizeof(double));
//         for (int j = 0; j < Acols; j++){
//             fscanf(fp, "%lf", &A[i][j]);
//         }
//     }
//     fclose(fp);
    
//     // Read second matrix B from "B.txt"
//     fp = fopen("B.txt", "r");
//     if (!fp) { perror("Error opening B.txt"); exit(1); }
//     int Brows, Bcols;
//     fscanf(fp, "%d %d", &Brows, &Bcols);
//     if (Acols != Brows) { 
//         printf("Matrix dimensions do not match for multiplication.\n");
//         exit(1);
//     }
//     double **B = malloc(Brows * sizeof(double*));
//     for (int i = 0; i < Brows; i++){
//         B[i] = malloc(Bcols * sizeof(double));
//         for (int j = 0; j < Bcols; j++){
//             fscanf(fp, "%lf", &B[i][j]);
//         }
//     }
//     fclose(fp);
    
//     // Allocate product matrix
//     double **product = malloc(Arows * sizeof(double*));
//     for (int i = 0; i < Arows; i++){
//         product[i] = calloc(Bcols, sizeof(double));
//     }
    
//     // Multiply matrices concurrently.
//     int numThreads = 4;
//     pthread_t threads[numThreads];
//     ProdTask tasks[numThreads];
//     int rowsPerThread = Arows / numThreads;
//     for (int t = 0; t < numThreads; t++){
//         tasks[t].startRow = t * rowsPerThread;
//         tasks[t].endRow = (t == numThreads - 1) ? Arows : (t+1)*rowsPerThread;
//         tasks[t].Arows = Arows;
//         tasks[t].Acols = Acols;
//         tasks[t].Bcols = Bcols;
//         tasks[t].A = A;
//         tasks[t].B = B;
//         tasks[t].product = product;
//         pthread_create(&threads[t], NULL, multiplyRows, &tasks[t]);
//     }
//     for (int t = 0; t < numThreads; t++){
//         pthread_join(threads[t], NULL);
//     }
    
//     // Apply threshold concurrently on the product matrix.
//     ThresholdTask threshTask[numThreads];
//     for (int t = 0; t < numThreads; t++){
//         threshTask[t].startRow = t * rowsPerThread;
//         threshTask[t].endRow = (t == numThreads - 1) ? Arows : (t+1)*rowsPerThread;
//         threshTask[t].rows = Arows;
//         threshTask[t].cols = Bcols;
//         threshTask[t].threshold = THRESHOLD;
//         threshTask[t].matrix = product;
//         pthread_create(&threads[t], NULL, applyThreshold, &threshTask[t]);
//     }
//     for (int t = 0; t < numThreads; t++){
//         pthread_join(threads[t], NULL);
//     }
    
//     printf("Modified product matrix after thresholding (threshold = %.2lf):\n", THRESHOLD);
//     for (int i = 0; i < Arows; i++){
//         for (int j = 0; j < Bcols; j++){
//             printf("%.0lf ", product[i][j]);
//         }
//         printf("\n");
//     }
    
//     // Cleanup
//     for (int i = 0; i < Arows; i++){
//         free(A[i]); free(product[i]);
//     }
//     for (int i = 0; i < Brows; i++){
//         free(B[i]);
//     }
//     free(A); free(B); free(product);
//     return 0;
// }

