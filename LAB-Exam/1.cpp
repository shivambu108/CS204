// 1. Matrix Addition

// #include <iostream>
// #include <pthread.h>
// using namespace std;

// const int ROWS = 3;
// const int COLS = 3;

// int A[ROWS][COLS] = { {1, 2, 3},
//                       {4, 5, 6},
//                       {7, 8, 9} };

// int B[ROWS][COLS] = { {9, 8, 7},
//                       {6, 5, 4},
//                       {3, 2, 1} };

// int C[ROWS][COLS];

// void* addRow(void* arg) {
//     int row = *(int*)arg;
//     for (int j = 0; j < COLS; j++) {
//         C[row][j] = A[row][j] + B[row][j];
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     pthread_t threads[ROWS];
//     int rowIndices[ROWS];

//     for (int i = 0; i < ROWS; i++) {
//         rowIndices[i] = i;
//         pthread_create(&threads[i], NULL, addRow, (void*)&rowIndices[i]);
//     }
//     for (int i = 0; i < ROWS; i++) {
//         pthread_join(threads[i], NULL);
//     }

//     cout << "Matrix Addition Result:" << endl;
//     for (int i = 0; i < ROWS; i++) {
//         for (int j = 0; j < COLS; j++) {
//             cout << C[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// 2. Matrix Multiplication

// #include <iostream>
// #include <pthread.h>
// using namespace std;

// const int ROWS_A = 3, COLS_A = 3, COLS_B = 3;

// int A[ROWS_A][COLS_A] = { {1, 2, 3},
//                           {4, 5, 6},
//                           {7, 8, 9} };

// int B[COLS_A][COLS_B] = { {9, 8, 7},
//                           {6, 5, 4},
//                           {3, 2, 1} };

// int C[ROWS_A][COLS_B];

// void* multiplyRow(void* arg) {
//     int row = *(int*)arg;
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
//     int rowIndices[ROWS_A];

//     for (int i = 0; i < ROWS_A; i++) {
//         rowIndices[i] = i;
//         pthread_create(&threads[i], NULL, multiplyRow, (void*)&rowIndices[i]);
//     }
//     for (int i = 0; i < ROWS_A; i++) {
//         pthread_join(threads[i], NULL);
//     }

//     cout << "Matrix Multiplication Result:" << endl;
//     for (int i = 0; i < ROWS_A; i++) {
//         for (int j = 0; j < COLS_B; j++) {
//             cout << C[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// 3. Matrix Transpose

// #include <iostream>
// #include <pthread.h>
// using namespace std;

// const int ROWS = 3, COLS = 3;

// int A[ROWS][COLS] = { {1, 2, 3},
//                       {4, 5, 6},
//                       {7, 8, 9} };

// int T[COLS][ROWS];  // Transposed matrix

// void* transposeRow(void* arg) {
//     int row = *(int*)arg;
//     for (int j = 0; j < COLS; j++) {
//         T[j][row] = A[row][j];
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     pthread_t threads[ROWS];
//     int rowIndices[ROWS];

//     for (int i = 0; i < ROWS; i++) {
//         rowIndices[i] = i;
//         pthread_create(&threads[i], NULL, transposeRow, (void*)&rowIndices[i]);
//     }
//     for (int i = 0; i < ROWS; i++) {
//         pthread_join(threads[i], NULL);
//     }

//     cout << "Matrix Transpose:" << endl;
//     for (int i = 0; i < COLS; i++) {
//         for (int j = 0; j < ROWS; j++) {
//             cout << T[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// 4. Determinant Calculation (3×3)

// #include <iostream>
// #include <pthread.h>
// using namespace std;

// const int SIZE = 3;
// double M[SIZE][SIZE] = { {1, 2, 3},
//                          {4, 5, 6},
//                          {7, 8, 9} };
// double terms[3] = {0};

// struct ThreadData {
//     int index;
// };

// void* computeTerm(void* arg) {
//     ThreadData* data = (ThreadData*) arg;
//     int i = data->index;
//     double term = 0;
//     if (i == 0) {
//         term = M[0][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1]);
//     } else if (i == 1) {
//         term = -M[0][1] * (M[1][0] * M[2][2] - M[1][2] * M[2][0]);
//     } else if (i == 2) {
//         term = M[0][2] * (M[1][0] * M[2][1] - M[1][1] * M[2][0]);
//     }
//     terms[i] = term;
//     pthread_exit(NULL);
// }

// int main() {
//     pthread_t threads[3];
//     ThreadData tdata[3];

//     for (int i = 0; i < 3; i++) {
//         tdata[i].index = i;
//         pthread_create(&threads[i], NULL, computeTerm, (void*)&tdata[i]);
//     }
//     for (int i = 0; i < 3; i++) {
//         pthread_join(threads[i], NULL);
//     }
//     double det = terms[0] + terms[1] + terms[2];
//     cout << "Determinant: " << det << endl;
//     return 0;
// }

// 5. Matrix Inversion (3×3)

// #include <iostream>
// #include <pthread.h>
// using namespace std;

// const int SIZE = 3;
// double M[SIZE][SIZE] = { {4, 7, 2},
//                          {3, 6, 1},
//                          {2, 5, 3} };

// double inv[SIZE][SIZE];
// double cofactors[SIZE][SIZE];

// struct CofactorData {
//     int row, col;
// };

// double computeMinor(int r, int c) {
//     double minor[2][2];
//     int m_row = 0;
//     for (int i = 0; i < SIZE; i++) {
//         if (i == r) continue;
//         int m_col = 0;
//         for (int j = 0; j < SIZE; j++) {
//             if (j == c) continue;
//             minor[m_row][m_col] = M[i][j];
//             m_col++;
//         }
//         m_row++;
//     }
//     return minor[0][0] * minor[1][1] - minor[0][1] * minor[1][0];
// }

// void* computeCofactor(void* arg) {
//     CofactorData* data = (CofactorData*) arg;
//     int r = data->row, c = data->col;
//     double minor = computeMinor(r, c);
//     double cofactor = ((r + c) % 2 == 0) ? minor : -minor;
//     cofactors[r][c] = cofactor;
//     pthread_exit(NULL);
// }

// int main() {
//     pthread_t threads[SIZE * SIZE];
//     CofactorData tdata[SIZE * SIZE];
//     int threadCount = 0;

//     // Create 9 threads to compute each cofactor
//     for (int i = 0; i < SIZE; i++) {
//         for (int j = 0; j < SIZE; j++) {
//             tdata[threadCount].row = i;
//             tdata[threadCount].col = j;
//             pthread_create(&threads[threadCount], NULL, computeCofactor, (void*)&tdata[threadCount]);
//             threadCount++;
//         }
//     }
//     for (int i = 0; i < threadCount; i++) {
//         pthread_join(threads[i], NULL);
//     }
//     // Compute determinant using the cofactors of the first row
//     double det = M[0][0] * cofactors[0][0] +
//                  M[0][1] * cofactors[0][1] +
//                  M[0][2] * cofactors[0][2];
//     if (det == 0) {
//         cout << "Matrix is singular, cannot invert." << endl;
//         return 1;
//     }
//     // Calculate the inverse as the transpose of the cofactor matrix divided by determinant
//     for (int i = 0; i < SIZE; i++) {
//         for (int j = 0; j < SIZE; j++) {
//             inv[j][i] = cofactors[i][j] / det;
//         }
//     }
//     cout << "Inverse Matrix:" << endl;
//     for (int i = 0; i < SIZE; i++) {
//         for (int j = 0; j < SIZE; j++) {
//             cout << inv[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }


// 6. Row-wise Sum with Threads

// #include <iostream>
// #include <pthread.h>
// using namespace std;

// const int ROWS = 4;
// const int COLS = 3;

// int matrix[ROWS][COLS] = { {1,  2,  3},
//                            {4,  5,  6},
//                            {7,  8,  9},
//                            {10, 11, 12} };

// int rowSums[ROWS];

// void* rowSum(void* arg) {
//     int row = *(int*)arg;
//     int sum = 0;
//     for (int j = 0; j < COLS; j++) {
//         sum += matrix[row][j];
//     }
//     rowSums[row] = sum;
//     pthread_exit(NULL);
// }

// int main() {
//     pthread_t threads[ROWS];
//     int rowIndices[ROWS];

//     for (int i = 0; i < ROWS; i++) {
//         rowIndices[i] = i;
//         pthread_create(&threads[i], NULL, rowSum, (void*)&rowIndices[i]);
//     }
//     for (int i = 0; i < ROWS; i++) {
//         pthread_join(threads[i], NULL);
//     }

//     cout << "Row-wise Sums:" << endl;
//     for (int i = 0; i < ROWS; i++) {
//         cout << "Row " << i << ": " << rowSums[i] << endl;
//     }
//     return 0;
// }

// 7. Column-wise Mean Calculation

// #include <iostream>
// #include <pthread.h>
// using namespace std;

// const int ROWS = 4;
// const int COLS = 3;

// int matrix[ROWS][COLS] = { {1,  2,  3},
//                            {4,  5,  6},
//                            {7,  8,  9},
//                            {10, 11, 12} };

// double colMeans[COLS];

// void* columnMean(void* arg) {
//     int col = *(int*)arg;
//     int sum = 0;
//     for (int i = 0; i < ROWS; i++) {
//         sum += matrix[i][col];
//     }
//     colMeans[col] = sum / static_cast<double>(ROWS);
//     pthread_exit(NULL);
// }

// int main() {
//     pthread_t threads[COLS];
//     int colIndices[COLS];

//     for (int j = 0; j < COLS; j++) {
//         colIndices[j] = j;
//         pthread_create(&threads[j], NULL, columnMean, (void*)&colIndices[j]);
//     }
//     for (int j = 0; j < COLS; j++) {
//         pthread_join(threads[j], NULL);
//     }

//     cout << "Column-wise Means:" << endl;
//     for (int j = 0; j < COLS; j++) {
//         cout << "Column " << j << ": " << colMeans[j] << endl;
//     }
//     return 0;
// }

// 8. Parallel Matrix Scalar Multiplication

// #include <iostream>
// #include <pthread.h>
// using namespace std;

// const int ROWS = 3;
// const int COLS = 3;

// int matrix[ROWS][COLS] = { {1, 2, 3},
//                            {4, 5, 6},
//                            {7, 8, 9} };

// int result[ROWS][COLS];
// int scalar = 5;

// void* scalarMultiply(void* arg) {
//     int row = *(int*)arg;
//     for (int j = 0; j < COLS; j++) {
//         result[row][j] = matrix[row][j] * scalar;
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     pthread_t threads[ROWS];
//     int rowIndices[ROWS];

//     for (int i = 0; i < ROWS; i++) {
//         rowIndices[i] = i;
//         pthread_create(&threads[i], NULL, scalarMultiply, (void*)&rowIndices[i]);
//     }
//     for (int i = 0; i < ROWS; i++) {
//         pthread_join(threads[i], NULL);
//     }

//     cout << "Result of Scalar Multiplication:" << endl;
//     for (int i = 0; i < ROWS; i++) {
//         for (int j = 0; j < COLS; j++) {
//             cout << result[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// 9. Matrix Subtraction

// #include <iostream>
// #include <pthread.h>
// using namespace std;

// const int ROWS = 3;
// const int COLS = 3;

// int A[ROWS][COLS] = { {9, 8, 7},
//                       {6, 5, 4},
//                       {3, 2, 1} };

// int B[ROWS][COLS] = { {1, 2, 3},
//                       {4, 5, 6},
//                       {7, 8, 9} };

// int C[ROWS][COLS];

// void* subtractRow(void* arg) {
//     int row = *(int*)arg;
//     for (int j = 0; j < COLS; j++) {
//         C[row][j] = A[row][j] - B[row][j];
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     pthread_t threads[ROWS];
//     int rowIndices[ROWS];

//     for (int i = 0; i < ROWS; i++) {
//         rowIndices[i] = i;
//         pthread_create(&threads[i], NULL, subtractRow, (void*)&rowIndices[i]);
//     }
//     for (int i = 0; i < ROWS; i++) {
//         pthread_join(threads[i], NULL);
//     }

//     cout << "Matrix Subtraction Result:" << endl;
//     for (int i = 0; i < ROWS; i++) {
//         for (int j = 0; j < COLS; j++) {
//             cout << C[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }


// 10. Combining Operations

// #include <iostream>
// #include <pthread.h>
// using namespace std;

// const int ROWS = 3;
// const int COLS = 3;

// int A[ROWS][COLS] = { {1, 2, 3},
//                       {4, 5, 6},
//                       {7, 8, 9} };

// int B[ROWS][COLS] = { {9, 8, 7},
//                       {6, 5, 4},
//                       {3, 2, 1} };

// int C[ROWS][COLS]; // Result of A+B

// int D[ROWS][COLS] = { {1, 0, 1},
//                       {0, 1, 0},
//                       {1, 0, 1} }; // Third matrix

// int result[ROWS][COLS];

// void* addRow(void* arg) {
//     int row = *(int*)arg;
//     for (int j = 0; j < COLS; j++) {
//         C[row][j] = A[row][j] + B[row][j];
//     }
//     pthread_exit(NULL);
// }

// void* multiplyRow(void* arg) {
//     int row = *(int*)arg;
//     for (int j = 0; j < COLS; j++) {
//         result[row][j] = 0;
//         for (int k = 0; k < COLS; k++) {
//             result[row][j] += C[row][k] * D[k][j];
//         }
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     pthread_t threadsAdd[ROWS], threadsMul[ROWS];
//     int rowIndices[ROWS];

//     // Addition phase (A + B)
//     for (int i = 0; i < ROWS; i++) {
//         rowIndices[i] = i;
//         pthread_create(&threadsAdd[i], NULL, addRow, (void*)&rowIndices[i]);
//     }
//     for (int i = 0; i < ROWS; i++) {
//         pthread_join(threadsAdd[i], NULL);
//     }

//     // Multiplication phase ((A+B) * D)
//     for (int i = 0; i < ROWS; i++) {
//         pthread_create(&threadsMul[i], NULL, multiplyRow, (void*)&rowIndices[i]);
//     }
//     for (int i = 0; i < ROWS; i++) {
//         pthread_join(threadsMul[i], NULL);
//     }

//     cout << "Result of Combining Operations (A+B)*D:" << endl;
//     for (int i = 0; i < ROWS; i++) {
//         for (int j = 0; j < COLS; j++) {
//             cout << result[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }


// 1. Nearest Row Search

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <cmath>
// #include <pthread.h>
// #include <algorithm>
// using namespace std;

// struct ThreadData {
//     int rowIndex;
// };

// vector<vector<double>> matrix;
// vector<double> target;
// vector<double> distances;
// int numRows, numCols;

// void* computeDistance(void* arg) {
//     ThreadData* data = (ThreadData*) arg;
//     int row = data->rowIndex;
//     double sum = 0.0;
//     for (int j = 0; j < numCols; j++) {
//         double diff = matrix[row][j] - target[j];
//         sum += diff * diff;
//     }
//     distances[row] = sqrt(sum);
//     pthread_exit(NULL);
// }

// int main() {
//     ifstream fin("matrix.txt");
//     if (!fin) {
//         cerr << "Error opening matrix.txt" << endl;
//         return 1;
//     }
//     fin >> numRows >> numCols;
//     matrix.resize(numRows, vector<double>(numCols));
//     distances.resize(numRows, 0.0);
//     for (int i = 0; i < numRows; i++)
//         for (int j = 0; j < numCols; j++)
//             fin >> matrix[i][j];
//     fin.close();
    
//     ifstream ftarget("target.txt");
//     if (!ftarget) {
//         cerr << "Error opening target.txt" << endl;
//         return 1;
//     }
//     int targetSize;
//     ftarget >> targetSize;
//     if (targetSize != numCols) {
//         cerr << "Target vector size does not match matrix column count." << endl;
//         return 1;
//     }
//     target.resize(targetSize);
//     for (int j = 0; j < targetSize; j++)
//         ftarget >> target[j];
//     ftarget.close();
    
//     vector<pthread_t> threads(numRows);
//     vector<ThreadData> threadData(numRows);
//     for (int i = 0; i < numRows; i++) {
//         threadData[i].rowIndex = i;
//         pthread_create(&threads[i], NULL, computeDistance, (void*)&threadData[i]);
//     }
//     for (int i = 0; i < numRows; i++)
//         pthread_join(threads[i], NULL);
    
//     // Sort row indices based on computed distance
//     vector<int> indices(numRows);
//     for (int i = 0; i < numRows; i++)
//         indices[i] = i;
//     sort(indices.begin(), indices.end(), [](int a, int b) {
//         return distances[a] < distances[b];
//     });
    
//     int numClosest = min(4, numRows);
//     cout << "The " << numClosest << " nearest rows to the target vector are:" << endl;
//     for (int i = 0; i < numClosest; i++) {
//         int idx = indices[i];
//         cout << "Row " << idx << " (Distance: " << distances[idx] << "): ";
//         for (int j = 0; j < numCols; j++)
//             cout << matrix[idx][j] << " ";
//         cout << endl;
//     }
//     return 0;
// }

// 2. Nearest Column Search

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <cmath>
// #include <pthread.h>
// #include <algorithm>
// using namespace std;

// struct ThreadData {
//     int colIndex;
// };

// vector<vector<double>> matrix;
// vector<double> target;
// vector<double> distances;
// int numRows, numCols;

// void* computeColumnDistance(void* arg) {
//     ThreadData* data = (ThreadData*) arg;
//     int col = data->colIndex;
//     double sum = 0.0;
//     for (int i = 0; i < numRows; i++) {
//         double diff = matrix[i][col] - target[i];
//         sum += diff * diff;
//     }
//     distances[col] = sqrt(sum);
//     pthread_exit(NULL);
// }

// int main() {
//     ifstream fin("matrix.txt");
//     if (!fin) {
//         cerr << "Error opening matrix.txt" << endl;
//         return 1;
//     }
//     fin >> numRows >> numCols;
//     matrix.resize(numRows, vector<double>(numCols));
//     for (int i = 0; i < numRows; i++)
//         for (int j = 0; j < numCols; j++)
//             fin >> matrix[i][j];
//     fin.close();
    
//     ifstream ftarget("target.txt");
//     if (!ftarget) {
//         cerr << "Error opening target.txt" << endl;
//         return 1;
//     }
//     int targetSize;
//     ftarget >> targetSize;
//     if (targetSize != numRows) {
//         cerr << "Target vector size does not match matrix row count." << endl;
//         return 1;
//     }
//     target.resize(targetSize);
//     for (int i = 0; i < targetSize; i++)
//         ftarget >> target[i];
//     ftarget.close();
    
//     distances.resize(numCols, 0.0);
//     vector<pthread_t> threads(numCols);
//     vector<ThreadData> threadData(numCols);
//     for (int j = 0; j < numCols; j++) {
//         threadData[j].colIndex = j;
//         pthread_create(&threads[j], NULL, computeColumnDistance, (void*)&threadData[j]);
//     }
//     for (int j = 0; j < numCols; j++)
//         pthread_join(threads[j], NULL);
    
//     vector<int> indices(numCols);
//     for (int j = 0; j < numCols; j++)
//         indices[j] = j;
//     sort(indices.begin(), indices.end(), [](int a, int b) {
//         return distances[a] < distances[b];
//     });
    
//     int numClosest = min(4, numCols);
//     cout << "The " << numClosest << " nearest columns to the target vector are:" << endl;
//     for (int i = 0; i < numClosest; i++) {
//         int idx = indices[i];
//         cout << "Column " << idx << " (Distance: " << distances[idx] << "): ";
//         for (int row = 0; row < numRows; row++)
//             cout << matrix[row][idx] << " ";
//         cout << endl;
//     }
//     return 0;
// }


// 3. Dot Product Maximizer

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <pthread.h>
// #include <limits>
// using namespace std;

// struct ThreadData {
//     int colIndex;
// };

// vector<vector<double>> matrix;
// vector<double> vec;
// vector<double> dotProducts;
// int numRows, numCols;

// void* computeDotProduct(void* arg) {
//     ThreadData* data = (ThreadData*) arg;
//     int col = data->colIndex;
//     double dot = 0.0;
//     for (int i = 0; i < numRows; i++)
//         dot += matrix[i][col] * vec[i];
//     dotProducts[col] = dot;
//     pthread_exit(NULL);
// }

// int main() {
//     ifstream fin("matrix.txt");
//     if (!fin) {
//         cerr << "Error opening matrix.txt" << endl;
//         return 1;
//     }
//     fin >> numRows >> numCols;
//     matrix.resize(numRows, vector<double>(numCols));
//     for (int i = 0; i < numRows; i++)
//         for (int j = 0; j < numCols; j++)
//             fin >> matrix[i][j];
//     fin.close();
    
//     ifstream fvec("vector.txt");
//     if (!fvec) {
//         cerr << "Error opening vector.txt" << endl;
//         return 1;
//     }
//     int vecSize;
//     fvec >> vecSize;
//     if (vecSize != numRows) {
//         cerr << "Vector size does not match number of rows in matrix." << endl;
//         return 1;
//     }
//     vec.resize(vecSize);
//     for (int i = 0; i < vecSize; i++)
//         fvec >> vec[i];
//     fvec.close();
    
//     dotProducts.resize(numCols, 0.0);
//     vector<pthread_t> threads(numCols);
//     vector<ThreadData> threadData(numCols);
//     for (int j = 0; j < numCols; j++) {
//         threadData[j].colIndex = j;
//         pthread_create(&threads[j], NULL, computeDotProduct, (void*)&threadData[j]);
//     }
//     for (int j = 0; j < numCols; j++)
//         pthread_join(threads[j], NULL);
    
//     int maxIndex = 0;
//     double maxDot = dotProducts[0];
//     for (int j = 1; j < numCols; j++) {
//         if (dotProducts[j] > maxDot) {
//             maxDot = dotProducts[j];
//             maxIndex = j;
//         }
//     }
//     cout << "The column with the highest dot product is at index " << maxIndex 
//          << " with a dot product of " << maxDot << endl;
//     return 0;
// }

// 4. Batch Matrix Inversion

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <pthread.h>
// #include <iomanip>
// using namespace std;

// struct MatrixData {
//     int index;
//     int n;
//     vector<vector<double>> mat;
//     vector<vector<double>> inv;
//     bool invertible;
// };

// vector<MatrixData> matrices;

// void printMatrix(const vector<vector<double>>& m) {
//     int n = m.size();
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++)
//             cout << m[i][j] << " ";
//         cout << endl;
//     }
// }

// bool invertMatrix(const vector<vector<double>>& input, vector<vector<double>>& output) {
//     int n = input.size();
//     output = vector<vector<double>>(n, vector<double>(n, 0));
//     vector<vector<double>> a = input;
    
//     // Initialize output as identity matrix
//     for (int i = 0; i < n; i++)
//         output[i][i] = 1;
    
//     for (int i = 0; i < n; i++) {
//         double pivot = a[i][i];
//         if (pivot == 0) {
//             int swapRow = -1;
//             for (int k = i+1; k < n; k++)
//                 if (a[k][i] != 0) { swapRow = k; break; }
//             if (swapRow == -1)
//                 return false;
//             swap(a[i], a[swapRow]);
//             swap(output[i], output[swapRow]);
//             pivot = a[i][i];
//         }
//         for (int j = 0; j < n; j++) {
//             a[i][j] /= pivot;
//             output[i][j] /= pivot;
//         }
//         for (int k = 0; k < n; k++) {
//             if (k != i) {
//                 double factor = a[k][i];
//                 for (int j = 0; j < n; j++) {
//                     a[k][j] -= factor * a[i][j];
//                     output[k][j] -= factor * output[i][j];
//                 }
//             }
//         }
//     }
//     return true;
// }

// void* invertMatrixThread(void* arg) {
//     MatrixData* data = (MatrixData*) arg;
//     data->invertible = invertMatrix(data->mat, data->inv);
//     pthread_exit(NULL);
// }

// int main() {
//     ifstream fin("matrices.txt");
//     if (!fin) {
//         cerr << "Error opening matrices.txt" << endl;
//         return 1;
//     }
//     int numMatrices;
//     fin >> numMatrices;
//     matrices.resize(numMatrices);
//     for (int m = 0; m < numMatrices; m++) {
//         int n;
//         fin >> n;
//         matrices[m].index = m;
//         matrices[m].n = n;
//         matrices[m].mat.resize(n, vector<double>(n));
//         for (int i = 0; i < n; i++)
//             for (int j = 0; j < n; j++)
//                 fin >> matrices[m].mat[i][j];
//     }
//     fin.close();
    
//     vector<pthread_t> threads(numMatrices);
//     for (int m = 0; m < numMatrices; m++)
//         pthread_create(&threads[m], NULL, invertMatrixThread, (void*)&matrices[m]);
//     for (int m = 0; m < numMatrices; m++)
//         pthread_join(threads[m], NULL);
    
//     for (int m = 0; m < numMatrices; m++) {
//         cout << "Matrix " << m << ":" << endl;
//         printMatrix(matrices[m].mat);
//         if (matrices[m].invertible) {
//             cout << "Inverse:" << endl;
//             printMatrix(matrices[m].inv);
//         } else {
//             cout << "This matrix is not invertible." << endl;
//         }
//         cout << "-------------------" << endl;
//     }
//     return 0;
// }

// 5. Global Sum Calculation

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <pthread.h>
// using namespace std;

// struct ThreadData {
//     int startRow;
//     int endRow;
//     long long sum;
// };

// vector<vector<int>> matrix;
// int numRows, numCols;
// int numThreads = 4;

// void* sumSegment(void* arg) {
//     ThreadData* data = (ThreadData*) arg;
//     data->sum = 0;
//     for (int i = data->startRow; i < data->endRow; i++)
//         for (int j = 0; j < numCols; j++)
//             data->sum += matrix[i][j];
//     pthread_exit(NULL);
// }

// int main() {
//     ifstream fin("matrix.txt");
//     if (!fin) {
//         cerr << "Error opening matrix.txt" << endl;
//         return 1;
//     }
//     fin >> numRows >> numCols;
//     matrix.resize(numRows, vector<int>(numCols));
//     for (int i = 0; i < numRows; i++)
//         for (int j = 0; j < numCols; j++)
//             fin >> matrix[i][j];
//     fin.close();
    
//     vector<ThreadData> threadData(numThreads);
//     vector<pthread_t> threads(numThreads);
//     int rowsPerThread = numRows / numThreads;
//     int extra = numRows % numThreads;
//     int currentRow = 0;
    
//     for (int t = 0; t < numThreads; t++) {
//         threadData[t].startRow = currentRow;
//         threadData[t].endRow = currentRow + rowsPerThread + (t < extra ? 1 : 0);
//         currentRow = threadData[t].endRow;
//         pthread_create(&threads[t], NULL, sumSegment, (void*)&threadData[t]);
//     }
//     long long totalSum = 0;
//     for (int t = 0; t < numThreads; t++) {
//         pthread_join(threads[t], NULL);
//         totalSum += threadData[t].sum;
//     }
    
//     cout << "Total sum of matrix elements: " << totalSum << endl;
//     return 0;
// }

// 6. Sliding Window Determinant

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <pthread.h>
// using namespace std;

// int numRows, numCols;
// int windowSize = 3;
// vector<vector<double>> matrix;

// struct Window {
//     int startRow;
//     int startCol;
// };

// vector<Window> windows;
// vector<double> determinants; // one per window

// struct ThreadData {
//     int startIndex;
//     int endIndex;
// };

// double computeDeterminant(const vector<vector<double>>& mat) {
//     int n = mat.size();
//     if (n == 1) return mat[0][0];
//     if (n == 2) return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
//     double det = 0.0;
//     for (int p = 0; p < n; p++) {
//         vector<vector<double>> submat(n-1, vector<double>(n-1));
//         for (int i = 1; i < n; i++) {
//             int colIndex = 0;
//             for (int j = 0; j < n; j++) {
//                 if (j == p) continue;
//                 submat[i-1][colIndex] = mat[i][j];
//                 colIndex++;
//             }
//         }
//         det += (p % 2 == 0 ? 1 : -1) * mat[0][p] * computeDeterminant(submat);
//     }
//     return det;
// }

// void* slidingWindowDeterminant(void* arg) {
//     ThreadData* data = (ThreadData*) arg;
//     for (int idx = data->startIndex; idx < data->endIndex; idx++) {
//         int r = windows[idx].startRow;
//         int c = windows[idx].startCol;
//         vector<vector<double>> submatrix(windowSize, vector<double>(windowSize));
//         for (int i = 0; i < windowSize; i++)
//             for (int j = 0; j < windowSize; j++)
//                 submatrix[i][j] = matrix[r+i][c+j];
//         determinants[idx] = computeDeterminant(submatrix);
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     ifstream fin("matrix.txt");
//     if (!fin) {
//         cerr << "Error opening matrix.txt" << endl;
//         return 1;
//     }
//     fin >> numRows >> numCols;
//     matrix.resize(numRows, vector<double>(numCols));
//     for (int i = 0; i < numRows; i++)
//         for (int j = 0; j < numCols; j++)
//             fin >> matrix[i][j];
//     fin.close();
    
//     // Generate all valid sliding window positions.
//     for (int i = 0; i <= numRows - windowSize; i++)
//         for (int j = 0; j <= numCols - windowSize; j++)
//             windows.push_back({i, j});
//     int totalWindows = windows.size();
//     determinants.resize(totalWindows, 0.0);
    
//     int numThreads = 4;
//     vector<pthread_t> threads(numThreads);
//     vector<ThreadData> threadData(numThreads);
//     int windowsPerThread = totalWindows / numThreads;
//     int extra = totalWindows % numThreads;
//     int currentIndex = 0;
//     for (int t = 0; t < numThreads; t++) {
//         threadData[t].startIndex = currentIndex;
//         threadData[t].endIndex = currentIndex + windowsPerThread + (t < extra ? 1 : 0);
//         currentIndex = threadData[t].endIndex;
//         pthread_create(&threads[t], NULL, slidingWindowDeterminant, (void*)&threadData[t]);
//     }
//     for (int t = 0; t < numThreads; t++)
//         pthread_join(threads[t], NULL);
    
//     // Output the determinant for each window.
//     for (int i = 0; i < totalWindows; i++) {
//         cout << "Window starting at (" << windows[i].startRow << ", " 
//              << windows[i].startCol << ") has determinant: " << determinants[i] << endl;
//     }
//     return 0;
// }

// 7. Self-Multiplication Check

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <pthread.h>
// #include <cmath>
// using namespace std;

// vector<vector<double>> matrix;
// vector<vector<double>> product;
// int numRows, numCols;

// struct ThreadData {
//     int rowIndex;
// };

// void* computeProductRow(void* arg) {
//     ThreadData* data = (ThreadData*) arg;
//     int i = data->rowIndex;
//     for (int j = 0; j < numRows; j++) {
//         double sum = 0.0;
//         for (int k = 0; k < numCols; k++)
//             sum += matrix[i][k] * matrix[j][k]; // Note: (A * Aᵀ)[i][j]
//         product[i][j] = sum;
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     ifstream fin("matrix.txt");
//     if (!fin) {
//         cerr << "Error opening matrix.txt" << endl;
//         return 1;
//     }
//     fin >> numRows >> numCols;
//     matrix.resize(numRows, vector<double>(numCols));
//     for (int i = 0; i < numRows; i++)
//         for (int j = 0; j < numCols; j++)
//             fin >> matrix[i][j];
//     fin.close();
    
//     product.resize(numRows, vector<double>(numRows, 0.0));
//     vector<pthread_t> threads(numRows);
//     vector<ThreadData> threadData(numRows);
//     for (int i = 0; i < numRows; i++) {
//         threadData[i].rowIndex = i;
//         pthread_create(&threads[i], NULL, computeProductRow, (void*)&threadData[i]);
//     }
//     for (int i = 0; i < numRows; i++)
//         pthread_join(threads[i], NULL);
    
//     // Check symmetry of product matrix.
//     bool symmetric = true;
//     double eps = 1e-6;
//     for (int i = 0; i < numRows; i++)
//         for (int j = i+1; j < numRows; j++)
//             if (fabs(product[i][j] - product[j][i]) > eps) {
//                 cout << "Discrepancy at (" << i << ", " << j << "): " 
//                      << product[i][j] << " vs " << product[j][i] << endl;
//                 symmetric = false;
//             }
    
//     if (symmetric)
//         cout << "The product matrix is symmetric." << endl;
//     else
//         cout << "The product matrix is not symmetric." << endl;
    
//     return 0;
// }


// 8. Inverse Verification

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <pthread.h>
// #include <cmath>
// using namespace std;

// vector<vector<double>> A, B, product;
// int n; // dimension of the square matrices

// struct ThreadData {
//     int rowIndex;
// };

// void* computeProductRow(void* arg) {
//     ThreadData* data = (ThreadData*) arg;
//     int i = data->rowIndex;
//     for (int j = 0; j < n; j++) {
//         double sum = 0.0;
//         for (int k = 0; k < n; k++)
//             sum += A[i][k] * B[k][j];
//         product[i][j] = sum;
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     ifstream finA("matrixA.txt");
//     if (!finA) {
//         cerr << "Error opening matrixA.txt" << endl;
//         return 1;
//     }
//     finA >> n;
//     A.resize(n, vector<double>(n));
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//             finA >> A[i][j];
//     finA.close();
    
//     ifstream finB("matrixB.txt");
//     if (!finB) {
//         cerr << "Error opening matrixB.txt" << endl;
//         return 1;
//     }
//     int nB;
//     finB >> nB;
//     if (nB != n) {
//         cerr << "Matrix dimensions do not match." << endl;
//         return 1;
//     }
//     B.resize(n, vector<double>(n));
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//             finB >> B[i][j];
//     finB.close();
    
//     product.resize(n, vector<double>(n, 0.0));
//     vector<pthread_t> threads(n);
//     vector<ThreadData> threadData(n);
//     for (int i = 0; i < n; i++) {
//         threadData[i].rowIndex = i;
//         pthread_create(&threads[i], NULL, computeProductRow, (void*)&threadData[i]);
//     }
//     for (int i = 0; i < n; i++)
//         pthread_join(threads[i], NULL);
    
//     // Check if product is approximately the identity matrix.
//     bool isIdentity = true;
//     double eps = 1e-6;
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++) {
//             double expected = (i == j) ? 1.0 : 0.0;
//             if (fabs(product[i][j] - expected) > eps) {
//                 cout << "Mismatch at (" << i << ", " << j << "): " 
//                      << product[i][j] << " vs " << expected << endl;
//                 isIdentity = false;
//             }
//         }
    
//     if (isIdentity)
//         cout << "Matrix B is the inverse of Matrix A." << endl;
//     else
//         cout << "Matrix B is not the inverse of Matrix A." << endl;
    
//     return 0;
// }


// 9. Target Row Sum Match

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <pthread.h>
// #include <cmath>
// using namespace std;

// vector<vector<double>> matrix;
// vector<double> rowSums;
// int numRows, numCols;
// double targetSum;

// struct ThreadData {
//     int rowIndex;
// };

// void* computeRowSum(void* arg) {
//     ThreadData* data = (ThreadData*) arg;
//     int i = data->rowIndex;
//     double sum = 0.0;
//     for (int j = 0; j < numCols; j++)
//         sum += matrix[i][j];
//     rowSums[i] = sum;
//     pthread_exit(NULL);
// }

// int main() {
//     ifstream fin("matrix.txt");
//     if (!fin) {
//         cerr << "Error opening matrix.txt" << endl;
//         return 1;
//     }
//     fin >> numRows >> numCols;
//     matrix.resize(numRows, vector<double>(numCols));
//     rowSums.resize(numRows, 0.0);
//     for (int i = 0; i < numRows; i++)
//         for (int j = 0; j < numCols; j++)
//             fin >> matrix[i][j];
//     fin.close();
    
//     ifstream ftarget("target.txt");
//     if (!ftarget) {
//         cerr << "Error opening target.txt" << endl;
//         return 1;
//     }
//     ftarget >> targetSum;
//     ftarget.close();
    
//     vector<pthread_t> threads(numRows);
//     vector<ThreadData> threadData(numRows);
//     for (int i = 0; i < numRows; i++) {
//         threadData[i].rowIndex = i;
//         pthread_create(&threads[i], NULL, computeRowSum, (void*)&threadData[i]);
//     }
//     for (int i = 0; i < numRows; i++)
//         pthread_join(threads[i], NULL);
    
//     int bestRow = 0;
//     double minDiff = fabs(rowSums[0] - targetSum);
//     for (int i = 1; i < numRows; i++) {
//         double diff = fabs(rowSums[i] - targetSum);
//         if (diff < minDiff) {
//             minDiff = diff;
//             bestRow = i;
//         }
//     }
    
//     cout << "Row " << bestRow << " has sum " << rowSums[bestRow] 
//          << " which is closest to target sum " << targetSum << endl;
//     return 0;
// }

// 1. Scalar–Matrix Combination

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <pthread.h>
// using namespace std;

// int numRows, numCols;
// vector<vector<double>> matrix;
// vector<vector<double>> scaledMatrix;
// double traceResult = 0.0;
// double scalar = 2.5;  // example scalar

// // Thread function to scale the matrix
// void* scaleMatrix(void* arg) {
//     scaledMatrix.resize(numRows, vector<double>(numCols, 0));
//     for (int i = 0; i < numRows; i++)
//         for (int j = 0; j < numCols; j++)
//             scaledMatrix[i][j] = matrix[i][j] * scalar;
//     pthread_exit(NULL);
// }

// // Thread function to compute the trace of the matrix
// void* computeTrace(void* arg) {
//     double sum = 0.0;
//     int n = (numRows < numCols) ? numRows : numCols;
//     for (int i = 0; i < n; i++)
//         sum += matrix[i][i];
//     traceResult = sum;
//     pthread_exit(NULL);
// }

// int main() {
//     ifstream fin("matrix.txt");
//     if (!fin) {
//         cerr << "Error opening matrix.txt" << endl;
//         return 1;
//     }
//     fin >> numRows >> numCols;
//     matrix.resize(numRows, vector<double>(numCols));
//     for (int i = 0; i < numRows; i++)
//         for (int j = 0; j < numCols; j++)
//             fin >> matrix[i][j];
//     fin.close();

//     pthread_t thread1, thread2;
//     pthread_create(&thread1, NULL, scaleMatrix, NULL);
//     pthread_create(&thread2, NULL, computeTrace, NULL);
//     pthread_join(thread1, NULL);
//     pthread_join(thread2, NULL);

//     cout << "Scaled Matrix (each element multiplied by " << scalar << "):\n";
//     for (int i = 0; i < numRows; i++) {
//         for (int j = 0; j < numCols; j++)
//             cout << scaledMatrix[i][j] << " ";
//         cout << "\n";
//     }
//     cout << "Trace of original matrix: " << traceResult << "\n";
//     return 0;
// }

// 2. Trace and Diagonal Difference

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <pthread.h>
// #include <cstdlib>
// #include <cmath>
// using namespace std;

// int numRows, numCols;
// vector<vector<double>> matrix;
// double traceSum = 0.0;
// double antiDiagSum = 0.0;

// // Thread to compute main diagonal (trace)
// void* computeTrace(void* arg) {
//     double sum = 0.0;
//     int n = (numRows < numCols) ? numRows : numCols;
//     for (int i = 0; i < n; i++)
//         sum += matrix[i][i];
//     traceSum = sum;
//     pthread_exit(NULL);
// }

// // Thread to compute anti-diagonal sum
// void* computeAntiDiagonal(void* arg) {
//     double sum = 0.0;
//     int n = (numRows < numCols) ? numRows : numCols;
//     for (int i = 0; i < n; i++)
//         sum += matrix[i][n - i - 1];
//     antiDiagSum = sum;
//     pthread_exit(NULL);
// }

// int main() {
//     ifstream fin("matrix.txt");
//     if (!fin) {
//         cerr << "Error opening matrix.txt" << endl;
//         return 1;
//     }
//     fin >> numRows >> numCols;
//     matrix.resize(numRows, vector<double>(numCols));
//     for (int i = 0; i < numRows; i++)
//         for (int j = 0; j < numCols; j++)
//             fin >> matrix[i][j];
//     fin.close();

//     pthread_t thread1, thread2;
//     pthread_create(&thread1, NULL, computeTrace, NULL);
//     pthread_create(&thread2, NULL, computeAntiDiagonal, NULL);
//     pthread_join(thread1, NULL);
//     pthread_join(thread2, NULL);

//     double diff = fabs(traceSum - antiDiagSum);
//     cout << "Trace: " << traceSum << "\n";
//     cout << "Anti-diagonal sum: " << antiDiagSum << "\n";
//     cout << "Absolute difference: " << diff << "\n";
//     return 0;
// }

// 3. LU Decomposition and Determinant

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <pthread.h>
// using namespace std;

// int n;
// vector<vector<double>> A, L, U;
// double detProduct = 1.0;

// // Perform LU decomposition using Doolittle's method (L diagonal = 1)
// void luDecomposition() {
//     L.resize(n, vector<double>(n, 0));
//     U.resize(n, vector<double>(n, 0));
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
//             if (U[i][i] == 0) {
//                 cerr << "Singular matrix\n";
//                 exit(1);
//             }
//             L[j][i] = (A[j][i] - sum) / U[i][i];
//         }
//     }
// }

// struct ThreadData {
//     int start;
//     int end;
//     double partialProduct;
// };

// void* computeDiagonalProduct(void* arg) {
//     ThreadData* data = (ThreadData*) arg;
//     data->partialProduct = 1.0;
//     for (int i = data->start; i < data->end; i++) {
//         data->partialProduct *= U[i][i];
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     ifstream fin("matrix.txt");
//     if (!fin) {
//         cerr << "Error opening matrix.txt" << endl;
//         return 1;
//     }
//     fin >> n;
//     A.resize(n, vector<double>(n));
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//             fin >> A[i][j];
//     fin.close();

//     luDecomposition();

//     // Use 2 threads to compute product of U's diagonal elements.
//     int numThreads = 2;
//     pthread_t threads[numThreads];
//     ThreadData threadData[numThreads];
//     int chunk = n / numThreads;
//     int extra = n % numThreads;
//     int current = 0;
//     for (int t = 0; t < numThreads; t++) {
//         threadData[t].start = current;
//         threadData[t].end = current + chunk + (t < extra ? 1 : 0);
//         current = threadData[t].end;
//         pthread_create(&threads[t], NULL, computeDiagonalProduct, (void*)&threadData[t]);
//     }
//     for (int t = 0; t < numThreads; t++) {
//         pthread_join(threads[t], NULL);
//         detProduct *= threadData[t].partialProduct;
//     }
//     cout << "Determinant (product of U diagonal): " << detProduct << "\n";
//     return 0;
// }

// 4. Parallel Gaussian Elimination

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <pthread.h>
// #include <iomanip>
// using namespace std;

// int n;
// vector<vector<double>> aug; // augmented matrix

// struct ElimData {
//     int pivot;
//     int row;  // row to update
// };

// pthread_mutex_t mtx;  // not strictly needed here since threads work on separate rows

// void* eliminate(void* arg) {
//     ElimData* data = (ElimData*) arg;
//     int i = data->row;
//     int pivot = data->pivot;
//     double factor = aug[i][pivot] / aug[pivot][pivot];
//     for (int j = pivot; j <= n; j++) {
//         aug[i][j] -= factor * aug[pivot][j];
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     ifstream fin("system.txt");
//     if (!fin) {
//         cerr << "Error opening system.txt" << endl;
//         return 1;
//     }
//     fin >> n;
//     aug.resize(n, vector<double>(n+1));
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j <= n; j++)
//             fin >> aug[i][j];
//     fin.close();

//     // Gaussian elimination
//     for (int pivot = 0; pivot < n - 1; pivot++) {
//         int numThreads = n - pivot - 1;
//         pthread_t threads[numThreads];
//         vector<ElimData> threadData(numThreads);
//         for (int i = pivot + 1, t = 0; i < n; i++, t++) {
//             threadData[t].pivot = pivot;
//             threadData[t].row = i;
//             pthread_create(&threads[t], NULL, eliminate, (void*)&threadData[t]);
//         }
//         for (int t = 0; t < numThreads; t++)
//             pthread_join(threads[t], NULL);
//     }

//     // Back substitution
//     vector<double> x(n);
//     for (int i = n - 1; i >= 0; i--) {
//         x[i] = aug[i][n];
//         for (int j = i + 1; j < n; j++) {
//             x[i] -= aug[i][j] * x[j];
//         }
//         x[i] /= aug[i][i];
//     }
//     cout << "Solution:\n";
//     for (int i = 0; i < n; i++)
//         cout << "x[" << i << "] = " << x[i] << "\n";
//     return 0;
// }


// 5. Inverse Verification with Residual

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <pthread.h>
// #include <cmath>
// using namespace std;

// int n;
// vector<vector<double>> A, inv, product;
 
// // Compute inverse using Gauss-Jordan elimination
// bool computeInverse(vector<vector<double>> A, vector<vector<double>>& inv) {
//     n = A.size();
//     inv.assign(n, vector<double>(n, 0));
//     for (int i = 0; i < n; i++) {
//         inv[i][i] = 1;
//     }
//     for (int i = 0; i < n; i++) {
//         double pivot = A[i][i];
//         if (fabs(pivot) < 1e-9)
//             return false;
//         for (int j = 0; j < n; j++) {
//             A[i][j] /= pivot;
//             inv[i][j] /= pivot;
//         }
//         for (int k = 0; k < n; k++) {
//             if (k == i) continue;
//             double factor = A[k][i];
//             for (int j = 0; j < n; j++) {
//                 A[k][j] -= factor * A[i][j];
//                 inv[k][j] -= factor * inv[i][j];
//             }
//         }
//     }
//     return true;
// }

// struct ThreadData {
//     int start;
//     int end;
// };

// void* multiplyPart(void* arg) {
//     ThreadData* data = (ThreadData*) arg;
//     for (int i = data->start; i < data->end; i++) {
//         for (int j = 0; j < n; j++) {
//             double sum = 0.0;
//             for (int k = 0; k < n; k++)
//                 sum += A[i][k] * inv[k][j];
//             product[i][j] = sum;
//         }
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     ifstream fin("matrix.txt");
//     if (!fin) {
//         cerr << "Error opening matrix.txt\n";
//         return 1;
//     }
//     fin >> n;
//     A.resize(n, vector<double>(n));
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//             fin >> A[i][j];
//     fin.close();

//     if (!computeInverse(A, inv)) {
//         cout << "Matrix is singular; cannot compute inverse.\n";
//         return 1;
//     }

//     product.resize(n, vector<double>(n, 0));
//     int numThreads = 4;
//     pthread_t threads[numThreads];
//     ThreadData threadData[numThreads];
//     int rowsPerThread = n / numThreads;
//     int extra = n % numThreads;
//     int current = 0;
//     for (int t = 0; t < numThreads; t++) {
//         threadData[t].start = current;
//         threadData[t].end = current + rowsPerThread + (t < extra ? 1 : 0);
//         current = threadData[t].end;
//         pthread_create(&threads[t], NULL, multiplyPart, (void*)&threadData[t]);
//     }
//     for (int t = 0; t < numThreads; t++)
//         pthread_join(threads[t], NULL);

//     // Calculate residual error: ||A*inv - I||
//     double error = 0.0;
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++) {
//             double expected = (i == j) ? 1.0 : 0.0;
//             error += fabs(product[i][j] - expected);
//         }
//     cout << "Residual error (sum of absolute differences): " << error << "\n";
//     return 0;
// }

// 6. Matrix–Vector Product and Norm

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <pthread.h>
// #include <cmath>
// using namespace std;

// int numRows, numCols, vecSize;
// vector<vector<double>> matrix;
// vector<double> vec, result;

// struct ThreadData {
//     int row;
// };

// void* computeDot(void* arg) {
//     ThreadData* data = (ThreadData*) arg;
//     int i = data->row;
//     double sum = 0.0;
//     for (int j = 0; j < numCols; j++)
//         sum += matrix[i][j] * vec[j];
//     result[i] = sum;
//     pthread_exit(NULL);
// }

// int main() {
//     ifstream fin("matrix.txt");
//     if (!fin) {
//         cerr << "Error opening matrix.txt\n";
//         return 1;
//     }
//     fin >> numRows >> numCols;
//     matrix.resize(numRows, vector<double>(numCols));
//     for (int i = 0; i < numRows; i++)
//         for (int j = 0; j < numCols; j++)
//             fin >> matrix[i][j];
//     fin.close();

//     ifstream fvec("vector.txt");
//     if (!fvec) {
//         cerr << "Error opening vector.txt\n";
//         return 1;
//     }
//     fvec >> vecSize;
//     if (vecSize != numCols) {
//         cerr << "Vector size must equal matrix columns.\n";
//         return 1;
//     }
//     vec.resize(vecSize);
//     for (int i = 0; i < vecSize; i++)
//         fvec >> vec[i];
//     fvec.close();

//     result.resize(numRows, 0.0);
//     vector<pthread_t> threads(numRows);
//     vector<ThreadData> threadData(numRows);
//     for (int i = 0; i < numRows; i++) {
//         threadData[i].row = i;
//         pthread_create(&threads[i], NULL, computeDot, (void*)&threadData[i]);
//     }
//     for (int i = 0; i < numRows; i++)
//         pthread_join(threads[i], NULL);

//     // Compute Euclidean norm of the result vector
//     double norm = 0.0;
//     for (double val : result)
//         norm += val * val;
//     norm = sqrt(norm);

//     cout << "Matrix-vector product:\n";
//     for (double val : result)
//         cout << val << " ";
//     cout << "\nEuclidean norm: " << norm << "\n";
//     return 0;
// }

// 7. Block Determinant Computation

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <pthread.h>
// using namespace std;

// int n;
// vector<vector<double>> M;
// double detA = 0.0, detD = 0.0;

// double computeDeterminant(const vector<vector<double>>& mat) {
//     int dim = mat.size();
//     if (dim == 1)
//         return mat[0][0];
//     if (dim == 2)
//         return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
//     double det = 0.0;
//     for (int p = 0; p < dim; p++) {
//         vector<vector<double>> submat(dim - 1, vector<double>(dim - 1));
//         for (int i = 1; i < dim; i++) {
//             int colIndex = 0;
//             for (int j = 0; j < dim; j++) {
//                 if (j == p) continue;
//                 submat[i-1][colIndex++] = mat[i][j];
//             }
//         }
//         det += (p % 2 == 0 ? 1 : -1) * mat[0][p] * computeDeterminant(submat);
//     }
//     return det;
// }

// struct ThreadData {
//     int block; // 0 for top-left, 1 for bottom-right
// };

// void* computeBlockDeterminant(void* arg) {
//     ThreadData* data = (ThreadData*) arg;
//     int half = n / 2;
//     vector<vector<double>> blockMat(half, vector<double>(half));
//     if (data->block == 0) {
//         // top-left block
//         for (int i = 0; i < half; i++)
//             for (int j = 0; j < half; j++)
//                 blockMat[i][j] = M[i][j];
//         detA = computeDeterminant(blockMat);
//     } else {
//         // bottom-right block
//         for (int i = half; i < n; i++)
//             for (int j = half; j < n; j++)
//                 blockMat[i - half][j - half] = M[i][j];
//         detD = computeDeterminant(blockMat);
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     ifstream fin("matrix.txt");
//     if (!fin) {
//         cerr << "Error opening matrix.txt\n";
//         return 1;
//     }
//     fin >> n;
//     if (n % 2 != 0) {
//         cerr << "Matrix dimension must be even for block partitioning.\n";
//         return 1;
//     }
//     M.resize(n, vector<double>(n));
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//             fin >> M[i][j];
//     fin.close();

//     pthread_t threads[2];
//     ThreadData data[2];
//     data[0].block = 0;
//     data[1].block = 1;
//     pthread_create(&threads[0], NULL, computeBlockDeterminant, (void*)&data[0]);
//     pthread_create(&threads[1], NULL, computeBlockDeterminant, (void*)&data[1]);
//     pthread_join(threads[0], NULL);
//     pthread_join(threads[1], NULL);

//     double totalDet = detA * detD;  // valid if off-diagonals are zero
//     cout << "Determinant of top-left block: " << detA << "\n";
//     cout << "Determinant of bottom-right block: " << detD << "\n";
//     cout << "Determinant of full matrix (assuming block-diagonal): " << totalDet << "\n";
//     return 0;
// }

// 8. Row Cumulative Sum

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <pthread.h>
// using namespace std;

// int numRows, numCols;
// vector<vector<double>> matrix;
// vector<double> rowAverage;

// struct ThreadData {
//     int row;
// };

// void* computeCumulativeSum(void* arg) {
//     ThreadData* data = (ThreadData*) arg;
//     int i = data->row;
//     double cumulative = 0.0;
//     for (int j = 0; j < numCols; j++) {
//         cumulative += matrix[i][j];
//     }
//     rowAverage[i] = cumulative / numCols;
//     pthread_exit(NULL);
// }

// int main() {
//     ifstream fin("matrix.txt");
//     if (!fin) {
//         cerr << "Error opening matrix.txt\n";
//         return 1;
//     }
//     fin >> numRows >> numCols;
//     matrix.resize(numRows, vector<double>(numCols));
//     rowAverage.resize(numRows, 0.0);
//     for (int i = 0; i < numRows; i++)
//         for (int j = 0; j < numCols; j++)
//             fin >> matrix[i][j];
//     fin.close();

//     vector<pthread_t> threads(numRows);
//     vector<ThreadData> threadData(numRows);
//     for (int i = 0; i < numRows; i++) {
//         threadData[i].row = i;
//         pthread_create(&threads[i], NULL, computeCumulativeSum, (void*)&threadData[i]);
//     }
//     for (int i = 0; i < numRows; i++)
//         pthread_join(threads[i], NULL);

//     cout << "Row averages based on cumulative sums:\n";
//     for (int i = 0; i < numRows; i++)
//         cout << "Row " << i << " average: " << rowAverage[i] << "\n";
//     return 0;
// }

// 9. Matrix Product and Element-wise Operations

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <pthread.h>
// using namespace std;

// int rows1, cols1, rows2, cols2;
// vector<vector<double>> M1, M2, product;
// double threshold = 10.0;

// struct ThreadData {
//     int row;
// };

// void* multiplyRow(void* arg) {
//     ThreadData* data = (ThreadData*) arg;
//     int i = data->row;
//     for (int j = 0; j < cols2; j++) {
//         double sum = 0.0;
//         for (int k = 0; k < cols1; k++)
//             sum += M1[i][k] * M2[k][j];
//         product[i][j] = sum;
//     }
//     pthread_exit(NULL);
// }

// void* thresholdRow(void* arg) {
//     ThreadData* data = (ThreadData*) arg;
//     int i = data->row;
//     for (int j = 0; j < cols2; j++) {
//         if (product[i][j] < threshold)
//             product[i][j] = 0;
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     ifstream fin1("matrix1.txt");
//     if (!fin1) {
//         cerr << "Error opening matrix1.txt\n";
//         return 1;
//     }
//     fin1 >> rows1 >> cols1;
//     M1.resize(rows1, vector<double>(cols1));
//     for (int i = 0; i < rows1; i++)
//         for (int j = 0; j < cols1; j++)
//             fin1 >> M1[i][j];
//     fin1.close();

//     ifstream fin2("matrix2.txt");
//     if (!fin2) {
//         cerr << "Error opening matrix2.txt\n";
//         return 1;
//     }
//     fin2 >> rows2 >> cols2;
//     if (cols1 != rows2) {
//         cerr << "Incompatible matrix dimensions for multiplication.\n";
//         return 1;
//     }
//     M2.resize(rows2, vector<double>(cols2));
//     for (int i = 0; i < rows2; i++)
//         for (int j = 0; j < cols2; j++)
//             fin2 >> M2[i][j];
//     fin2.close();

//     product.resize(rows1, vector<double>(cols2, 0));

//     // Multiply matrices concurrently (one thread per row)
//     vector<pthread_t> threadsMul(rows1);
//     vector<ThreadData> threadData(rows1);
//     for (int i = 0; i < rows1; i++) {
//         threadData[i].row = i;
//         pthread_create(&threadsMul[i], NULL, multiplyRow, (void*)&threadData[i]);
//     }
//     for (int i = 0; i < rows1; i++)
//         pthread_join(threadsMul[i], NULL);

//     // Apply threshold concurrently (one thread per row)
//     vector<pthread_t> threadsThresh(rows1);
//     for (int i = 0; i < rows1; i++) {
//         pthread_create(&threadsThresh[i], NULL, thresholdRow, (void*)&threadData[i]);
//     }
//     for (int i = 0; i < rows1; i++)
//         pthread_join(threadsThresh[i], NULL);

//     cout << "Modified Product Matrix after thresholding (threshold = " << threshold << "):\n";
//     for (int i = 0; i < rows1; i++) {
//         for (int j = 0; j < cols2; j++)
//             cout << product[i][j] << " ";
//         cout << "\n";
//     }
//     return 0;
// }


