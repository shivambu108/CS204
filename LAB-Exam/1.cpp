// 1. Matrix Addition

// #include <iostream>
// #include <vector>
// #include <thread>
// using namespace std;

// void addRow(const vector<vector<int>> &A, const vector<vector<int>> &B,
//             vector<vector<int>> &C, int row) {
//     for (size_t j = 0; j < A[0].size(); ++j)
//         C[row][j] = A[row][j] + B[row][j];
// }

// int main() {
//     int rows = 3, cols = 3;
//     vector<vector<int>> A = { {1,2,3}, {4,5,6}, {7,8,9} };
//     vector<vector<int>> B = { {9,8,7}, {6,5,4}, {3,2,1} };
//     vector<vector<int>> C(rows, vector<int>(cols, 0));

//     vector<thread> threads;
//     for (int i = 0; i < rows; i++){
//         threads.emplace_back(addRow, cref(A), cref(B), ref(C), i);
//     }
//     for(auto &t : threads)
//         t.join();

//     cout << "Matrix Addition Result:\n";
//     for(auto &row: C){
//         for(auto val: row)
//             cout << val << " ";
//         cout << "\n";
//     }
//     return 0;
// }


// 2. Matrix Multiplication

// #include <iostream>
// #include <vector>
// #include <thread>
// using namespace std;

// void multiplyRow(const vector<vector<int>> &A, const vector<vector<int>> &B,
//                    vector<vector<int>> &C, int row) {
//     int cols = B[0].size();
//     int inner = B.size();
//     for (int j = 0; j < cols; j++) {
//         C[row][j] = 0;
//         for (int k = 0; k < inner; k++) {
//             C[row][j] += A[row][k] * B[k][j];
//         }
//     }
// }

// int main(){
//     vector<vector<int>> A = { {1,2,3},
//                               {4,5,6},
//                               {7,8,9} };

//     vector<vector<int>> B = { {9,8,7},
//                               {6,5,4},
//                               {3,2,1} };

//     int rows = A.size();
//     int cols = B[0].size();
//     vector<vector<int>> C(rows, vector<int>(cols, 0));

//     vector<thread> threads;
//     for (int i = 0; i < rows; i++){
//         threads.emplace_back(multiplyRow, cref(A), cref(B), ref(C), i);
//     }
//     for(auto &t : threads)
//         t.join();

//     cout << "Matrix Multiplication Result:\n";
//     for(auto &row: C){
//         for(auto val: row)
//             cout << val << " ";
//         cout << "\n";
//     }
//     return 0;
// }

// 3. Matrix Transpose

// #include <iostream>
// #include <vector>
// #include <thread>
// using namespace std;

// void transposeRow(const vector<vector<int>> &A, vector<vector<int>> &B, int row) {
//     for (size_t j = 0; j < A[0].size(); j++) {
//         B[j][row] = A[row][j];
//     }
// }

// int main(){
//     vector<vector<int>> A = { {1,2,3},
//                               {4,5,6} };

//     int rows = A.size(), cols = A[0].size();
//     // Transposed matrix dimensions: cols x rows.
//     vector<vector<int>> B(cols, vector<int>(rows, 0));

//     vector<thread> threads;
//     for (int i = 0; i < rows; i++){
//         threads.emplace_back(transposeRow, cref(A), ref(B), i);
//     }
//     for(auto &t : threads)
//         t.join();

//     cout << "Matrix Transpose Result:\n";
//     for(auto &row: B){
//         for(auto val: row)
//             cout << val << " ";
//         cout << "\n";
//     }
//     return 0;
// }

// 4. Determinant Calculation (3x3 Matrix)

// #include <iostream>
// #include <vector>
// #include <thread>
// #include <cmath>
// using namespace std;

// double det2x2(const vector<vector<double>> &M) {
//     return M[0][0]*M[1][1] - M[0][1]*M[1][0];
// }

// void cofactorTerm(const vector<vector<double>> &A, int j, double &result) {
//     vector<vector<double>> minor(2, vector<double>(2));
//     int m_row = 0;
//     for (int i = 1; i < 3; ++i) {
//         int m_col = 0;
//         for (int k = 0; k < 3; ++k) {
//             if(k == j) continue;
//             minor[m_row][m_col++] = A[i][k];
//         }
//         m_row++;
//     }
//     result = pow(-1, j) * A[0][j] * det2x2(minor);
// }

// int main() {
//     vector<vector<double>> A = {
//         {1, 2, 3},
//         {0, 4, 5},
//         {1, 0, 6}
//     };
//     double partial[3] = {0, 0, 0};
//     thread t[3];
//     for (int j = 0; j < 3; j++){
//         t[j] = thread(cofactorTerm, cref(A), j, ref(partial[j]));
//     }
//     for (int j = 0; j < 3; j++){
//         t[j].join();
//     }
//     double determinant = partial[0] + partial[1] + partial[2];
//     cout << "Determinant: " << determinant << "\n";
//     return 0;
// }

// 5. Matrix Inversion (3x3 Matrix)

// #include <iostream>
// #include <vector>
// #include <thread>
// #include <cmath>
// using namespace std;

// double det2x2(const vector<vector<double>> &M) {
//     return M[0][0]*M[1][1] - M[0][1]*M[1][0];
// }

// void computeCofactor(const vector<vector<double>> &A, int i, int j, double &cofactor) {
//     vector<vector<double>> minor;
//     for(int r = 0; r < 3; r++){
//         if(r == i) continue;
//         vector<double> row;
//         for(int c = 0; c < 3; c++){
//             if(c == j) continue;
//             row.push_back(A[r][c]);
//         }
//         minor.push_back(row);
//     }
//     cofactor = pow(-1, i+j) * det2x2(minor);
// }

// double determinant(const vector<vector<double>> &A) {
//     double det = 0;
//     for (int j = 0; j < 3; j++){
//         vector<vector<double>> minor;
//         for (int r = 1; r < 3; r++){
//             vector<double> row;
//             for (int c = 0; c < 3; c++){
//                 if(c == j) continue;
//                 row.push_back(A[r][c]);
//             }
//             minor.push_back(row);
//         }
//         det += pow(-1, j) * A[0][j] * det2x2(minor);
//     }
//     return det;
// }

// int main(){
//     vector<vector<double>> A = {
//         {4, 7, 2},
//         {3, 6, 1},
//         {2, 5, 1}
//     };
//     double det = determinant(A);
//     if(det == 0) {
//         cout << "Matrix is singular, cannot invert.\n";
//         return 0;
//     }
//     vector<vector<double>> cofactors(3, vector<double>(3, 0));
//     vector<thread> threads;
//     for (int i = 0; i < 3; i++){
//         for(int j = 0; j < 3; j++){
//             threads.emplace_back(computeCofactor, cref(A), i, j, ref(cofactors[i][j]));
//         }
//     }
//     for(auto &t: threads) {
//         t.join();
//     }
//     // Transpose the cofactor matrix to get the adjugate.
//     vector<vector<double>> adj(3, vector<double>(3, 0));
//     for(int i = 0; i < 3; i++){
//         for(int j = 0; j < 3; j++){
//             adj[i][j] = cofactors[j][i];
//         }
//     }
//     // Inverse = adjugate / determinant.
//     vector<vector<double>> inv(3, vector<double>(3, 0));
//     for (int i = 0; i < 3; i++){
//         for(int j = 0; j < 3; j++){
//             inv[i][j] = adj[i][j] / det;
//         }
//     }
//     cout << "Inverse Matrix:\n";
//     for(auto &row: inv){
//         for(auto val: row)
//             cout << val << " ";
//         cout << "\n";
//     }
//     return 0;
// }


// 6. Row-wise Sum with Threads

// #include <iostream>
// #include <vector>
// #include <thread>
// using namespace std;

// void sumRow(const vector<int> &row, int &sum) {
//     sum = 0;
//     for(auto val: row)
//         sum += val;
// }

// int main(){
//     vector<vector<int>> matrix = {
//         {1,2,3},
//         {4,5,6},
//         {7,8,9}
//     };
//     vector<int> rowSums(matrix.size(), 0);
//     vector<thread> threads;
//     for (size_t i = 0; i < matrix.size(); i++){
//         threads.emplace_back(sumRow, cref(matrix[i]), ref(rowSums[i]));
//     }
//     for(auto &t : threads)
//         t.join();

//     for (size_t i = 0; i < rowSums.size(); i++){
//         cout << "Sum of row " << i << ": " << rowSums[i] << "\n";
//     }
//     return 0;
// }

// 7. Column-wise Mean Calculation

// #include <iostream>
// #include <vector>
// #include <thread>
// using namespace std;

// void computeColumnMean(const vector<vector<int>> &matrix, int col, double &mean) {
//     int sum = 0;
//     int rows = matrix.size();
//     for (int i = 0; i < rows; i++){
//         sum += matrix[i][col];
//     }
//     mean = static_cast<double>(sum) / rows;
// }

// int main(){
//     vector<vector<int>> matrix = {
//         {1,2,3},
//         {4,5,6},
//         {7,8,9}
//     };
//     int cols = matrix[0].size();
//     vector<double> colMeans(cols, 0.0);
//     vector<thread> threads;
//     for (int j = 0; j < cols; j++){
//         threads.emplace_back(computeColumnMean, cref(matrix), j, ref(colMeans[j]));
//     }
//     for(auto &t : threads)
//         t.join();

//     for (int j = 0; j < cols; j++){
//         cout << "Mean of column " << j << ": " << colMeans[j] << "\n";
//     }
//     return 0;
// }


// 8. Parallel Matrix Scalar Multiplication

// #include <iostream>
// #include <vector>
// #include <thread>
// using namespace std;

// void scalarMultiplyRow(const vector<vector<int>> &matrix, vector<vector<int>> &result,
//                          int row, int scalar) {
//     for(size_t j = 0; j < matrix[0].size(); j++){
//         result[row][j] = matrix[row][j] * scalar;
//     }
// }

// int main(){
//     int scalar = 3;
//     vector<vector<int>> matrix = {
//         {1,2,3},
//         {4,5,6},
//         {7,8,9}
//     };
//     int rows = matrix.size();
//     int cols = matrix[0].size();
//     vector<vector<int>> result(rows, vector<int>(cols, 0));

//     vector<thread> threads;
//     for (int i = 0; i < rows; i++){
//         threads.emplace_back(scalarMultiplyRow, cref(matrix), ref(result), i, scalar);
//     }
//     for(auto &t: threads)
//         t.join();

//     cout << "Result of Scalar Multiplication:\n";
//     for(auto &row : result){
//         for(auto val : row)
//             cout << val << " ";
//         cout << "\n";
//     }
//     return 0;
// }

// 9. Matrix Subtraction

// #include <iostream>
// #include <vector>
// #include <thread>
// using namespace std;

// void subtractRow(const vector<vector<int>> &A, const vector<vector<int>> &B,
//                  vector<vector<int>> &C, int row) {
//     for (size_t j = 0; j < A[0].size(); j++){
//         C[row][j] = A[row][j] - B[row][j];
//     }
// }

// int main(){
//     vector<vector<int>> A = { {9,8,7}, {6,5,4}, {3,2,1} };
//     vector<vector<int>> B = { {1,2,3}, {4,5,6}, {7,8,9} };
//     int rows = A.size(), cols = A[0].size();
//     vector<vector<int>> C(rows, vector<int>(cols, 0));

//     vector<thread> threads;
//     for(int i = 0; i < rows; i++){
//         threads.emplace_back(subtractRow, cref(A), cref(B), ref(C), i);
//     }
//     for(auto &t: threads)
//         t.join();

//     cout << "Matrix Subtraction Result:\n";
//     for(auto &row : C){
//         for(auto val : row)
//             cout << val << " ";
//         cout << "\n";
//     }
//     return 0;
// }


// 10. Combining Operations

// #include <iostream>
// #include <vector>
// #include <thread>
// using namespace std;

// void addRow(const vector<vector<int>> &A, const vector<vector<int>> &B,
//             vector<vector<int>> &Sum, int row) {
//     for (size_t j = 0; j < A[0].size(); j++){
//         Sum[row][j] = A[row][j] + B[row][j];
//     }
// }

// void multiplyRow(const vector<vector<int>> &M, const vector<vector<int>> &C,
//                    vector<vector<int>> &Result, int row) {
//     int cols = C[0].size();
//     int inner = C.size();
//     for(int j = 0; j < cols; j++){
//         Result[row][j] = 0;
//         for(int k = 0; k < inner; k++){
//             Result[row][j] += M[row][k] * C[k][j];
//         }
//     }
// }

// int main(){
//     vector<vector<int>> A = { {1,2}, {3,4} };
//     vector<vector<int>> B = { {5,6}, {7,8} };
//     vector<vector<int>> C = { {1,0}, {0,1} }; // Using the identity matrix for simplicity.

//     int rows = A.size();
//     int cols = A[0].size();
//     vector<vector<int>> Sum(rows, vector<int>(cols, 0));

//     // Matrix addition using threads.
//     vector<thread> threads;
//     for (int i = 0; i < rows; i++){
//         threads.emplace_back(addRow, cref(A), cref(B), ref(Sum), i);
//     }
//     for(auto &t : threads)
//         t.join();

//     // Matrix multiplication: (A+B) * C.
//     int resultRows = Sum.size();
//     int resultCols = C[0].size();
//     vector<vector<int>> Result(resultRows, vector<int>(resultCols, 0));
//     threads.clear();
//     for (int i = 0; i < resultRows; i++){
//         threads.emplace_back(multiplyRow, cref(Sum), cref(C), ref(Result), i);
//     }
//     for(auto &t : threads)
//         t.join();

//     cout << "Result of (A+B)*C:\n";
//     for(auto &row: Result){
//         for(auto val : row)
//             cout << val << " ";
//         cout << "\n";
//     }
//     return 0;
// }


// 1. Nearest Row Search

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <sstream>
// #include <thread>
// #include <cmath>
// #include <mutex>
// #include <algorithm>
// using namespace std;

// struct RowDistance {
//     int index;
//     double distance;
// };

// void computeDistance(const vector<double>& target, const vector<double>& row, int idx, double &dist) {
//     double sum = 0;
//     for (size_t i = 0; i < target.size(); ++i)
//         sum += (row[i] - target[i]) * (row[i] - target[i]);
//     dist = sqrt(sum);
// }

// int main(){
//     ifstream matrixFile("matrix.txt");
//     ifstream targetFile("target.txt");
//     if (!matrixFile || !targetFile) {
//         cerr << "Error opening files.\n";
//         return 1;
//     }

//     int m, n;
//     matrixFile >> m >> n;
//     vector<vector<double>> matrix(m, vector<double>(n));
//     for (int i = 0; i < m; ++i)
//         for (int j = 0; j < n; ++j)
//             matrixFile >> matrix[i][j];

//     int tsize;
//     targetFile >> tsize;
//     if(tsize != n){
//         cerr << "Target vector size does not match matrix columns.\n";
//         return 1;
//     }
//     vector<double> target(tsize);
//     for (int i = 0; i < tsize; ++i)
//         target[i] = 0, targetFile >> target[i];

//     vector<double> distances(m);
//     vector<thread> threads;
//     for (int i = 0; i < m; ++i) {
//         threads.emplace_back(computeDistance, cref(target), cref(matrix[i]), i, ref(distances[i]));
//     }
//     for(auto &t: threads)
//         t.join();

//     vector<RowDistance> rd;
//     for (int i = 0; i < m; i++){
//         rd.push_back({i, distances[i]});
//     }
//     sort(rd.begin(), rd.end(), [](const RowDistance &a, const RowDistance &b) {
//         return a.distance < b.distance;
//     });

//     cout << "Four nearest rows to the target:\n";
//     for (int i = 0; i < 4 && i < (int)rd.size(); i++){
//         cout << "Row " << rd[i].index << " (Distance: " << rd[i].distance << "): ";
//         for (auto val : matrix[rd[i].index])
//             cout << val << " ";
//         cout << "\n";
//     }
//     return 0;
// }

// 2. Nearest Column Search

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <sstream>
// #include <thread>
// #include <cmath>
// #include <mutex>
// #include <algorithm>
// using namespace std;

// struct ColDistance {
//     int index;
//     double distance;
// };

// void computeColDistance(const vector<double>& target, const vector<vector<double>> &matrix, int col, double &dist) {
//     double sum = 0;
//     int rows = matrix.size();
//     for (int i = 0; i < rows; i++)
//         sum += (matrix[i][col] - target[i]) * (matrix[i][col] - target[i]);
//     dist = sqrt(sum);
// }

// int main(){
//     ifstream matrixFile("matrix.txt");
//     ifstream targetFile("target.txt");
//     if (!matrixFile || !targetFile) {
//         cerr << "Error opening files.\n";
//         return 1;
//     }

//     int m, n;
//     matrixFile >> m >> n;
//     vector<vector<double>> matrix(m, vector<double>(n));
//     for (int i = 0; i < m; ++i)
//         for (int j = 0; j < n; ++j)
//             matrixFile >> matrix[i][j];

//     int tsize;
//     targetFile >> tsize;
//     if(tsize != m){
//         cerr << "Target vector size does not match matrix rows.\n";
//         return 1;
//     }
//     vector<double> target(tsize);
//     for (int i = 0; i < tsize; ++i)
//         target[i] = 0, targetFile >> target[i];

//     vector<double> distances(n);
//     vector<thread> threads;
//     for (int j = 0; j < n; j++){
//         threads.emplace_back(computeColDistance, cref(target), cref(matrix), j, ref(distances[j]));
//     }
//     for(auto &t : threads)
//         t.join();

//     vector<ColDistance> cd;
//     for (int j = 0; j < n; j++){
//         cd.push_back({j, distances[j]});
//     }
//     sort(cd.begin(), cd.end(), [](const ColDistance &a, const ColDistance &b) {
//         return a.distance < b.distance;
//     });

//     cout << "Four nearest columns to the target:\n";
//     for (int i = 0; i < 4 && i < (int)cd.size(); i++){
//         cout << "Column " << cd[i].index << " (Distance: " << cd[i].distance << "): ";
//         for (int r = 0; r < m; r++)
//             cout << matrix[r][cd[i].index] << " ";
//         cout << "\n";
//     }
//     return 0;
// }

// 3. Dot Product Maximizer

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <sstream>
// #include <thread>
// #include <mutex>
// #include <limits>
// using namespace std;

// void dotProductColumn(const vector<vector<double>> &matrix, const vector<double> &vec, int col, double &result) {
//     int rows = matrix.size();
//     result = 0;
//     for (int i = 0; i < rows; i++){
//         result += matrix[i][col] * vec[i];
//     }
// }

// int main(){
//     ifstream matrixFile("matrix.txt");
//     ifstream vectorFile("vector.txt");
//     if (!matrixFile || !vectorFile) {
//         cerr << "Error opening files.\n";
//         return 1;
//     }
    
//     int m, n;
//     matrixFile >> m >> n;
//     vector<vector<double>> matrix(m, vector<double>(n));
//     for (int i = 0; i < m; ++i)
//         for (int j = 0; j < n; ++j)
//             matrixFile >> matrix[i][j];

//     int vsize;
//     vectorFile >> vsize;
//     if(vsize != m){
//         cerr << "Vector size must equal number of matrix rows.\n";
//         return 1;
//     }
//     vector<double> vec(vsize);
//     for (int i = 0; i < vsize; ++i)
//         vectorFile >> vec[i];

//     vector<double> dotProducts(n);
//     vector<thread> threads;
//     for (int j = 0; j < n; j++){
//         threads.emplace_back(dotProductColumn, cref(matrix), cref(vec), j, ref(dotProducts[j]));
//     }
//     for(auto &t : threads)
//         t.join();

//     int bestIndex = -1;
//     double bestDot = -numeric_limits<double>::infinity();
//     for (int j = 0; j < n; j++){
//         if(dotProducts[j] > bestDot){
//             bestDot = dotProducts[j];
//             bestIndex = j;
//         }
//     }
//     cout << "Column with maximum dot product: " << bestIndex << " (Dot Product = " << bestDot << ")\n";
//     return 0;
// }


// 4. Batch Matrix Inversion

// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <vector>
// #include <thread>
// #include <mutex>
// #include <cmath>
// using namespace std;

// typedef vector<vector<double>> Matrix;

// double det2x2(const Matrix &M) {
//     return M[0][0]*M[1][1] - M[0][1]*M[1][0];
// }

// double determinant(const Matrix &A) {
//     // For 3x3 matrix
//     double det = A[0][0]*(A[1][1]*A[2][2]-A[1][2]*A[2][1])
//                - A[0][1]*(A[1][0]*A[2][2]-A[1][2]*A[2][0])
//                + A[0][2]*(A[1][0]*A[2][1]-A[1][1]*A[2][0]);
//     return det;
// }

// bool invertMatrix(const Matrix &A, Matrix &inv) {
//     double det = determinant(A);
//     if(det == 0) return false;
//     inv = Matrix(3, vector<double>(3, 0));
//     inv[0][0] =  (A[1][1]*A[2][2]-A[1][2]*A[2][1]) / det;
//     inv[0][1] = -(A[0][1]*A[2][2]-A[0][2]*A[2][1]) / det;
//     inv[0][2] =  (A[0][1]*A[1][2]-A[0][2]*A[1][1]) / det;
//     inv[1][0] = -(A[1][0]*A[2][2]-A[1][2]*A[2][0]) / det;
//     inv[1][1] =  (A[0][0]*A[2][2]-A[0][2]*A[2][0]) / det;
//     inv[1][2] = -(A[0][0]*A[1][2]-A[0][2]*A[1][0]) / det;
//     inv[2][0] =  (A[1][0]*A[2][1]-A[1][1]*A[2][0]) / det;
//     inv[2][1] = -(A[0][0]*A[2][1]-A[0][1]*A[2][0]) / det;
//     inv[2][2] =  (A[0][0]*A[1][1]-A[0][1]*A[1][0]) / det;
//     return true;
// }

// void processMatrix(const Matrix &mat, int idx, vector<Matrix> &inverses, vector<int> &failures, mutex &m) {
//     Matrix inv;
//     if(invertMatrix(mat, inv)){
//         lock_guard<mutex> lock(m);
//         inverses[idx] = inv;
//     } else {
//         lock_guard<mutex> lock(m);
//         failures.push_back(idx);
//     }
// }

// int main(){
//     ifstream file("matrices.txt");
//     if(!file){
//         cerr << "Cannot open matrices.txt\n";
//         return 1;
//     }
//     vector<Matrix> matrices;
//     string line;
//     Matrix current;
//     while(getline(file, line)){
//         if(line.empty()){
//             if(!current.empty()){
//                 matrices.push_back(current);
//                 current.clear();
//             }
//         } else {
//             istringstream iss(line);
//             vector<double> row;
//             double num;
//             while(iss >> num)
//                 row.push_back(num);
//             current.push_back(row);
//         }
//     }
//     if(!current.empty())
//         matrices.push_back(current);

//     int count = matrices.size();
//     vector<Matrix> inverses(count, Matrix());
//     vector<int> failures;
//     mutex m;
//     vector<thread> threads;
//     for (int i = 0; i < count; i++){
//         // Assuming each matrix is 3x3.
//         threads.emplace_back(processMatrix, cref(matrices[i]), i, ref(inverses), ref(failures), ref(m));
//     }
//     for(auto &t: threads)
//         t.join();

//     for (int i = 0; i < count; i++){
//         cout << "Matrix " << i << " inverse:\n";
//         if(inverses[i].empty()){
//             cout << "  Not invertible.\n";
//         } else {
//             for(auto &row : inverses[i]){
//                 for(auto val : row)
//                     cout << val << " ";
//                 cout << "\n";
//             }
//         }
//     }
//     if(!failures.empty()){
//         cout << "Noninvertible matrices at indices: ";
//         for (auto idx : failures)
//             cout << idx << " ";
//         cout << "\n";
//     }
//     return 0;
// }


// 5. Global Sum Calculation

// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <vector>
// #include <thread>
// using namespace std;

// void partialSum(const vector<vector<int>> &matrix, int start, int end, long long &sum) {
//     long long localSum = 0;
//     for (int i = start; i < end; i++){
//         for (auto val : matrix[i])
//             localSum += val;
//     }
//     sum = localSum;
// }

// int main(){
//     ifstream file("matrix.txt");
//     if(!file){
//         cerr << "Cannot open matrix.txt\n";
//         return 1;
//     }
//     int m, n;
//     file >> m >> n;
//     vector<vector<int>> matrix(m, vector<int>(n));
//     for (int i = 0; i < m; i++){
//         for (int j = 0; j < n; j++){
//             file >> matrix[i][j];
//         }
//     }
    
//     int numThreads = 4;
//     vector<thread> threads;
//     vector<long long> sums(numThreads, 0);
//     int rowsPerThread = m / numThreads;
    
//     for (int t = 0; t < numThreads; t++){
//         int start = t * rowsPerThread;
//         int end = (t == numThreads - 1) ? m : start + rowsPerThread;
//         threads.emplace_back(partialSum, cref(matrix), start, end, ref(sums[t]));
//     }
//     for(auto &t: threads)
//         t.join();

//     long long total = 0;
//     for (auto s : sums)
//         total += s;
//     cout << "Total sum of matrix elements: " << total << "\n";
//     return 0;
// }


// 6. Sliding Window Determinant

// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <vector>
// #include <thread>
// #include <mutex>
// using namespace std;

// double determinant3x3(const vector<vector<double>> &win) {
//     return win[0][0]*(win[1][1]*win[2][2]-win[1][2]*win[2][1])
//          - win[0][1]*(win[1][0]*win[2][2]-win[1][2]*win[2][0])
//          + win[0][2]*(win[1][0]*win[2][1]-win[1][1]*win[2][0]);
// }

// void processWindows(const vector<vector<double>> &matrix, int startRow, int endRow, int windowSize, vector<pair<int, int>> &posDet, mutex &m) {
//     int totalRows = matrix.size();
//     int totalCols = matrix[0].size();
//     for (int i = startRow; i <= endRow; i++){
//         for (int j = 0; j <= totalCols - windowSize; j++){
//             // Make sure window fits vertically.
//             if(i + windowSize - 1 >= totalRows) break;
//             vector<vector<double>> win(windowSize, vector<double>(windowSize));
//             for (int a = 0; a < windowSize; a++){
//                 for (int b = 0; b < windowSize; b++){
//                     win[a][b] = matrix[i+a][j+b];
//                 }
//             }
//             double det = determinant3x3(win);
//             // For demonstration, we record positions with nonzero determinant.
//             if(det != 0){
//                 lock_guard<mutex> lock(m);
//                 posDet.push_back({i, j});
//             }
//         }
//     }
// }

// int main(){
//     ifstream file("matrix.txt");
//     if(!file){
//         cerr << "Cannot open matrix.txt\n";
//         return 1;
//     }
//     int m, n;
//     file >> m >> n;
//     vector<vector<double>> matrix(m, vector<double>(n));
//     for (int i = 0; i < m; i++){
//         for (int j = 0; j < n; j++){
//             file >> matrix[i][j];
//         }
//     }
    
//     int windowSize = 3;
//     int numThreads = 4;
//     vector<thread> threads;
//     vector<pair<int,int>> results; // stores top-left coordinate of window with nonzero determinant
//     mutex mtx;
    
//     int maxStartRow = m - windowSize;
//     int rowsPerThread = (maxStartRow + 1) / numThreads;
    
//     for (int t = 0; t < numThreads; t++){
//         int start = t * rowsPerThread;
//         int end = (t == numThreads - 1) ? maxStartRow : start + rowsPerThread - 1;
//         threads.emplace_back(processWindows, cref(matrix), start, end, windowSize, ref(results), ref(mtx));
//     }
//     for(auto &t : threads)
//         t.join();

//     cout << "Sliding window positions (top-left indices) with nonzero determinant:\n";
//     for (auto &p : results)
//         cout << "(" << p.first << ", " << p.second << ")\n";
//     return 0;
// }


// 7. Self-Multiplication Check

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <thread>
// using namespace std;

// void multiplyRowTranspose(const vector<vector<double>> &matrix, vector<vector<double>> &prod, int row) {
//     int m = matrix.size();
//     int n = matrix[0].size();
//     for (int j = 0; j < m; j++){
//         double sum = 0;
//         for (int k = 0; k < n; k++){
//             sum += matrix[row][k] * matrix[j][k];
//         }
//         prod[row][j] = sum;
//     }
// }

// int main(){
//     ifstream file("matrix.txt");
//     if(!file){
//         cerr << "Cannot open matrix.txt\n";
//         return 1;
//     }
//     int m, n;
//     file >> m >> n;
//     vector<vector<double>> matrix(m, vector<double>(n));
//     for (int i = 0; i < m; i++){
//         for (int j = 0; j < n; j++){
//             file >> matrix[i][j];
//         }
//     }
//     vector<vector<double>> prod(m, vector<double>(m, 0));
//     vector<thread> threads;
//     for (int i = 0; i < m; i++){
//         threads.emplace_back(multiplyRowTranspose, cref(matrix), ref(prod), i);
//     }
//     for(auto &t : threads)
//         t.join();

//     bool symmetric = true;
//     for (int i = 0; i < m && symmetric; i++){
//         for (int j = 0; j < m; j++){
//             if(prod[i][j] != prod[j][i]){
//                 cout << "Discrepancy at (" << i << "," << j << "): " << prod[i][j] << " vs " << prod[j][i] << "\n";
//                 symmetric = false;
//             }
//         }
//     }
//     if(symmetric)
//         cout << "The product matrix is symmetric.\n";
//     return 0;
// }

// 8. Inverse Verification

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <thread>
// #include <cmath>
// using namespace std;

// void multiplyRow(const vector<vector<double>> &A, const vector<vector<double>> &B, vector<vector<double>> &P, int row) {
//     int n = B.size();
//     for (int j = 0; j < n; j++){
//         double sum = 0;
//         for (int k = 0; k < n; k++){
//             sum += A[row][k] * B[k][j];
//         }
//         P[row][j] = sum;
//     }
// }

// bool isIdentity(const vector<vector<double>> &P, double tol = 1e-6) {
//     int n = P.size();
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < n; j++){
//             double expected = (i==j)? 1.0 : 0.0;
//             if (fabs(P[i][j]-expected) > tol)
//                 return false;
//         }
//     }
//     return true;
// }

// Matrix readMatrix(const string &filename) {
//     ifstream file(filename);
//     int n, m;
//     file >> n >> m;
//     vector<vector<double>> mat(n, vector<double>(m));
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < m; j++)
//             file >> mat[i][j];
//     return mat;
// }

// int main(){
//     auto A = readMatrix("matrixA.txt");
//     auto B = readMatrix("matrixB.txt");
//     int n = A.size();
//     vector<vector<double>> product(n, vector<double>(n, 0));
//     vector<thread> threads;
//     for (int i = 0; i < n; i++){
//         threads.emplace_back(multiplyRow, cref(A), cref(B), ref(product), i);
//     }
//     for(auto &t: threads)
//         t.join();
//     if(isIdentity(product))
//         cout << "MatrixB is the inverse of MatrixA.\n";
//     else
//         cout << "MatrixB is NOT the inverse of MatrixA.\n";
//     return 0;
// }

// 9. Target Row Sum Match


// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <thread>
// #include <cmath>
// #include <limits>
// using namespace std;

// void rowSum(const vector<int> &row, int &sum) {
//     sum = 0;
//     for (auto val : row)
//         sum += val;
// }

// int main(){
//     ifstream matrixFile("matrix.txt");
//     ifstream targetFile("target.txt");
//     if(!matrixFile || !targetFile){
//         cerr << "Error opening file(s).\n";
//         return 1;
//     }
//     int m, n;
//     matrixFile >> m >> n;
//     vector<vector<int>> matrix(m, vector<int>(n));
//     for (int i = 0; i < m; i++){
//         for (int j = 0; j < n; j++){
//             matrixFile >> matrix[i][j];
//         }
//     }
//     int target;
//     targetFile >> target;
    
//     vector<int> sums(m, 0);
//     vector<thread> threads;
//     for (int i = 0; i < m; i++){
//         threads.emplace_back(rowSum, cref(matrix[i]), ref(sums[i]));
//     }
//     for(auto &t : threads)
//         t.join();

//     int bestRow = -1;
//     int bestDiff = numeric_limits<int>::max();
//     for (int i = 0; i < m; i++){
//         int diff = abs(sums[i] - target);
//         if(diff < bestDiff){
//             bestDiff = diff;
//             bestRow = i;
//         }
//     }
//     cout << "Row " << bestRow << " has the sum " << sums[bestRow] << " which is closest to target " << target << ".\n";
//     return 0;
// }


// 1. Scalar–Matrix Combination

// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <vector>
// #include <thread>
// using namespace std;

// typedef vector<vector<double>> Matrix;

// void readMatrix(const string &filename, Matrix &mat) {
//     ifstream fin(filename);
//     if(!fin){
//         cerr << "Error opening " << filename << "\n";
//         exit(1);
//     }
//     int m, n;
//     fin >> m >> n;
//     mat.resize(m, vector<double>(n));
//     for (int i = 0; i < m; i++)
//         for (int j = 0; j < n; j++)
//             fin >> mat[i][j];
// }

// void scaleMatrix(const Matrix &in, Matrix &out, double scalar) {
//     int m = in.size(), n = in[0].size();
//     out.resize(m, vector<double>(n));
//     for (int i = 0; i < m; i++)
//         for (int j = 0; j < n; j++)
//             out[i][j] = in[i][j] * scalar;
// }

// void computeTrace(const Matrix &mat, double &trace) {
//     int m = mat.size(), n = mat[0].size();
//     trace = 0;
//     int diag = m < n ? m : n;
//     for (int i = 0; i < diag; i++)
//         trace += mat[i][i];
// }

// int main(){
//     Matrix A;
//     readMatrix("matrix.txt", A);
//     double scalar = 2.5; // example scalar

//     Matrix scaled;
//     double trace = 0;

//     thread t1(scaleMatrix, cref(A), ref(scaled), scalar);
//     thread t2(computeTrace, cref(A), ref(trace));
//     t1.join();
//     t2.join();

//     cout << "Scaled Matrix:\n";
//     for (auto &row : scaled) {
//         for (auto val : row)
//             cout << val << " ";
//         cout << "\n";
//     }
//     cout << "Trace = " << trace << "\n";
//     return 0;
// }


// 2. Trace and Diagonal Difference

// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <vector>
// #include <thread>
// #include <cmath>
// using namespace std;

// typedef vector<vector<double>> Matrix;

// void readMatrix(const string &filename, Matrix &mat) {
//     ifstream fin(filename);
//     if(!fin){
//         cerr << "Error opening " << filename << "\n";
//         exit(1);
//     }
//     int n, m;
//     fin >> n >> m;
//     mat.resize(n, vector<double>(m));
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < m; j++)
//             fin >> mat[i][j];
// }

// void computeTrace(const Matrix &mat, double &trace) {
//     int n = mat.size();
//     trace = 0;
//     for (int i = 0; i < n; i++)
//         trace += mat[i][i];
// }

// void computeAntiDiagonal(const Matrix &mat, double &anti) {
//     int n = mat.size();
//     anti = 0;
//     for (int i = 0; i < n; i++)
//         anti += mat[i][n - 1 - i];
// }

// int main(){
//     Matrix A;
//     readMatrix("matrix.txt", A);

//     double trace = 0, anti = 0;
//     thread t1(computeTrace, cref(A), ref(trace));
//     thread t2(computeAntiDiagonal, cref(A), ref(anti));
//     t1.join();
//     t2.join();

//     cout << "Trace = " << trace << "\n";
//     cout << "Anti-Diagonal Sum = " << anti << "\n";
//     cout << "Absolute Difference = " << fabs(trace - anti) << "\n";
//     return 0;
// }

// 3. LU Decomposition and Determinant


// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <thread>
// using namespace std;

// typedef vector<vector<double>> Matrix;

// void readMatrix(const string &filename, Matrix &mat) {
//     ifstream fin(filename);
//     if (!fin) {
//         cerr << "Error opening " << filename << "\n";
//         exit(1);
//     }
//     int n, m;
//     fin >> n >> m;
//     mat.resize(n, vector<double>(m));
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < m; j++)
//             fin >> mat[i][j];
// }

// void luDecomposition(const Matrix &A, Matrix &L, Matrix &U) {
//     int n = A.size();
//     L.assign(n, vector<double>(n, 0));
//     U.assign(n, vector<double>(n, 0));
//     for (int i = 0; i < n; i++) {
//         // Upper Triangular
//         for (int k = i; k < n; k++) {
//             double sum = 0;
//             for (int j = 0; j < i; j++)
//                 sum += L[i][j] * U[j][k];
//             U[i][k] = A[i][k] - sum;
//         }
//         // Lower Triangular
//         for (int k = i; k < n; k++) {
//             if (i == k)
//                 L[i][i] = 1;
//             else {
//                 double sum = 0;
//                 for (int j = 0; j < i; j++)
//                     sum += L[k][j] * U[j][i];
//                 L[k][i] = (A[k][i] - sum) / U[i][i];
//             }
//         }
//     }
// }

// void diagProduct(const Matrix &M, double &prod) {
//     int n = M.size();
//     prod = 1;
//     for (int i = 0; i < n; i++)
//         prod *= M[i][i];
// }

// int main(){
//     Matrix A;
//     readMatrix("matrix.txt", A);
//     int n = A.size();

//     Matrix L, U;
//     luDecomposition(A, L, U);

//     double prodL = 0, prodU = 0;
//     thread t1(diagProduct, cref(L), ref(prodL));
//     thread t2(diagProduct, cref(U), ref(prodU));
//     t1.join();
//     t2.join();

//     double determinant = prodL * prodU;
//     cout << "Determinant = " << determinant << "\n";
//     return 0;
// }


// 4. Parallel Gaussian Elimination


// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <vector>
// #include <thread>
// #include <iomanip>
// using namespace std;

// typedef vector<vector<double>> Matrix;

// void readSystem(const string &filename, Matrix &aug) {
//     ifstream fin(filename);
//     if(!fin){
//         cerr << "Error opening " << filename << "\n";
//         exit(1);
//     }
//     int n;
//     fin >> n;
//     aug.resize(n, vector<double>(n+1));
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n+1; j++)
//             fin >> aug[i][j];
// }

// void eliminateRow(Matrix &aug, int pivot, int row) {
//     int n = aug.size();
//     double factor = aug[row][pivot] / aug[pivot][pivot];
//     for (int j = pivot; j < n+1; j++) {
//         aug[row][j] -= factor * aug[pivot][j];
//     }
// }

// int main(){
//     Matrix aug;
//     readSystem("system.txt", aug);
//     int n = aug.size();

//     // Forward elimination
//     for (int pivot = 0; pivot < n - 1; pivot++) {
//         vector<thread> threads;
//         for (int row = pivot + 1; row < n; row++) {
//             threads.emplace_back(eliminateRow, ref(aug), pivot, row);
//         }
//         for (auto &t : threads)
//             t.join();
//     }

//     // Back substitution
//     vector<double> x(n, 0);
//     for (int i = n-1; i >= 0; i--) {
//         x[i] = aug[i][n];
//         for (int j = i+1; j < n; j++) {
//             x[i] -= aug[i][j] * x[j];
//         }
//         x[i] /= aug[i][i];
//     }

//     cout << "Solution Vector:\n";
//     for (auto xi : x)
//         cout << fixed << setprecision(4) << xi << " ";
//     cout << "\n";
//     return 0;
// }


// 5. Inverse Verification with Residual


// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <vector>
// #include <thread>
// #include <cmath>
// using namespace std;

// typedef vector<vector<double>> Matrix;

// bool invertMatrix(const Matrix &A, Matrix &inv) {
//     // Assuming a 3x3 matrix; no pivoting.
//     inv.resize(3, vector<double>(3, 0));
//     double det = A[0][0]*(A[1][1]*A[2][2]-A[1][2]*A[2][1])
//                - A[0][1]*(A[1][0]*A[2][2]-A[1][2]*A[2][0])
//                + A[0][2]*(A[1][0]*A[2][1]-A[1][1]*A[2][0]);
//     if(det == 0) return false;
//     inv[0][0] =  (A[1][1]*A[2][2]-A[1][2]*A[2][1]) / det;
//     inv[0][1] = -(A[0][1]*A[2][2]-A[0][2]*A[2][1]) / det;
//     inv[0][2] =  (A[0][1]*A[1][2]-A[0][2]*A[1][1]) / det;
//     inv[1][0] = -(A[1][0]*A[2][2]-A[1][2]*A[2][0]) / det;
//     inv[1][1] =  (A[0][0]*A[2][2]-A[0][2]*A[2][0]) / det;
//     inv[1][2] = -(A[0][0]*A[1][2]-A[0][2]*A[1][0]) / det;
//     inv[2][0] =  (A[1][0]*A[2][1]-A[1][1]*A[2][0]) / det;
//     inv[2][1] = -(A[0][0]*A[2][1]-A[0][1]*A[2][0]) / det;
//     inv[2][2] =  (A[0][0]*A[1][1]-A[0][1]*A[1][0]) / det;
//     return true;
// }

// void multiplyPartial(const Matrix &A, const Matrix &B, Matrix &C, int start, int end) {
//     int n = A.size();
//     for (int i = start; i < end; i++) {
//         for (int j = 0; j < n; j++) {
//             double sum = 0;
//             for (int k = 0; k < n; k++)
//                 sum += A[i][k] * B[k][j];
//             C[i][j] = sum;
//         }
//     }
// }

// int main(){
//     ifstream fin("matrix.txt");
//     if(!fin){
//         cerr << "Cannot open matrix.txt\n";
//         return 1;
//     }
//     // Assuming a 3x3 matrix
//     Matrix A(3, vector<double>(3));
//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 3; j++)
//             fin >> A[i][j];

//     Matrix Ainv;
//     if(!invertMatrix(A, Ainv)){
//         cerr << "Matrix is non-invertible.\n";
//         return 1;
//     }

//     Matrix product(3, vector<double>(3, 0));
//     int numThreads = 3;
//     vector<thread> threads;
//     int rowsPerThread = 3 / numThreads;
//     for (int t = 0; t < numThreads; t++){
//         int start = t * rowsPerThread;
//         int end = (t == numThreads - 1) ? 3 : start + rowsPerThread;
//         threads.emplace_back(multiplyPartial, cref(A), cref(Ainv), ref(product), start, end);
//     }
//     for (auto &t : threads)
//         t.join();

//     // Compute residual error ||A*Ainv - I||
//     double residual = 0;
//     for (int i = 0; i < 3; i++){
//         for (int j = 0; j < 3; j++){
//             double expected = (i == j) ? 1.0 : 0.0;
//             residual += fabs(product[i][j] - expected);
//         }
//     }
//     cout << "Residual error = " << residual << "\n";
//     return 0;
// }


// 6. Matrix–Vector Product and Norm

// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <vector>
// #include <thread>
// #include <cmath>
// using namespace std;

// typedef vector<vector<double>> Matrix;

// void readMatrix(const string &filename, Matrix &mat) {
//     ifstream fin(filename);
//     if(!fin){
//         cerr << "Error opening " << filename << "\n";
//         exit(1);
//     }
//     int m, n;
//     fin >> m >> n;
//     mat.resize(m, vector<double>(n));
//     for (int i = 0; i < m; i++)
//         for (int j = 0; j < n; j++)
//             fin >> mat[i][j];
// }

// void readVector(const string &filename, vector<double> &vec) {
//     ifstream fin(filename);
//     if(!fin){
//         cerr << "Error opening " << filename << "\n";
//         exit(1);
//     }
//     int n;
//     fin >> n;
//     vec.resize(n);
//     for (int i = 0; i < n; i++)
//         fin >> vec[i];
// }

// void computeRowProduct(const vector<double> &row, const vector<double> &vec, double &res) {
//     res = 0;
//     for (size_t j = 0; j < row.size(); j++)
//         res += row[j] * vec[j];
// }

// int main(){
//     Matrix A;
//     vector<double> vec;
//     readMatrix("matrix.txt", A);
//     readVector("vector.txt", vec);

//     int m = A.size();
//     vector<double> result(m, 0);
//     vector<thread> threads;
//     for (int i = 0; i < m; i++){
//         threads.emplace_back(computeRowProduct, cref(A[i]), cref(vec), ref(result[i]));
//     }
//     for (auto &t : threads)
//         t.join();

//     double norm = 0;
//     for (auto val : result)
//         norm += val * val;
//     norm = sqrt(norm);

//     cout << "Matrix-Vector Product:\n";
//     for (auto val : result)
//         cout << val << " ";
//     cout << "\nEuclidean Norm = " << norm << "\n";
//     return 0;
// }


// 7. Block Determinant Computation

// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <vector>
// #include <thread>
// using namespace std;

// typedef vector<vector<double>> Matrix;

// double determinant2x2(const Matrix &M) {
//     return M[0][0]*M[1][1] - M[0][1]*M[1][0];
// }

// double determinant3x3(const Matrix &M) {
//     return M[0][0]*(M[1][1]*M[2][2]-M[1][2]*M[2][1])
//          - M[0][1]*(M[1][0]*M[2][2]-M[1][2]*M[2][0])
//          + M[0][2]*(M[1][0]*M[2][1]-M[1][1]*M[2][0]);
// }

// // For simplicity, we assume blocks are 2x2.
// double detBlock(const Matrix &block) {
//     if(block.size() == 2)
//         return determinant2x2(block);
//     // Add other sizes as needed.
//     return 0;
// }

// void readMatrix(const string &filename, Matrix &mat) {
//     ifstream fin(filename);
//     if(!fin){
//         cerr << "Error opening " << filename << "\n";
//         exit(1);
//     }
//     int m, n;
//     fin >> m >> n;
//     mat.resize(m, vector<double>(n));
//     for (int i = 0; i < m; i++)
//         for (int j = 0; j < n; j++)
//             fin >> mat[i][j];
// }

// int main(){
//     Matrix A;
//     readMatrix("matrix.txt", A);
//     int n = A.size();
//     if(n % 2 != 0){
//         cerr << "Matrix size not even, cannot partition into equal blocks.\n";
//         return 1;
//     }
//     int half = n / 2;
//     // Partition A into 4 blocks: A11, A12, A21, A22.
//     Matrix A11(half, vector<double>(half));
//     Matrix A12(half, vector<double>(half));
//     Matrix A21(half, vector<double>(half));
//     Matrix A22(half, vector<double>(half));
//     for (int i = 0; i < half; i++){
//         for (int j = 0; j < half; j++){
//             A11[i][j] = A[i][j];
//             A12[i][j] = A[i][j+half];
//             A21[i][j] = A[i+half][j];
//             A22[i][j] = A[i+half][j+half];
//         }
//     }
//     double detA11 = 0, detA22 = 0;
//     thread t1([&](){ detA11 = detBlock(A11); });
//     thread t2([&](){ detA22 = detBlock(A22); });
//     t1.join();
//     t2.join();

//     // Assuming off-diagonal blocks are zeros, the determinant of A = det(A11)*det(A22)
//     double detA = detA11 * detA22;
//     cout << "Determinant of A (from block computation) = " << detA << "\n";
//     return 0;
// }


// 8. Row Cumulative Sum

// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <vector>
// #include <thread>
// using namespace std;

// typedef vector<vector<double>> Matrix;

// void readMatrix(const string &filename, Matrix &mat) {
//     ifstream fin(filename);
//     if(!fin){
//         cerr << "Error opening " << filename << "\n";
//         exit(1);
//     }
//     int m, n;
//     fin >> m >> n;
//     mat.resize(m, vector<double>(n));
//     for (int i = 0; i < m; i++)
//         for (int j = 0; j < n; j++)
//             fin >> mat[i][j];
// }

// void computeRowSum(const vector<double> &row, double &sum) {
//     sum = 0;
//     for (auto val : row)
//         sum += val;
// }

// int main(){
//     Matrix A;
//     readMatrix("matrix.txt", A);
//     int m = A.size(), n = A[0].size();
//     vector<double> rowSums(m, 0);
//     vector<thread> threads;
//     for (int i = 0; i < m; i++){
//         threads.emplace_back(computeRowSum, cref(A[i]), ref(rowSums[i]));
//     }
//     for (auto &t : threads)
//         t.join();
//     cout << "Row averages:\n";
//     for (int i = 0; i < m; i++){
//         double avg = rowSums[i] / n;
//         cout << "Row " << i << " average = " << avg << "\n";
//     }
//     return 0;
// }

// 9. Matrix Product and Element-wise Operations

// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <vector>
// #include <thread>
// using namespace std;

// typedef vector<vector<double>> Matrix;

// void readMatrix(const string &filename, Matrix &mat) {
//     ifstream fin(filename);
//     if(!fin){
//         cerr << "Error opening " << filename << "\n";
//         exit(1);
//     }
//     int m, n;
//     fin >> m >> n;
//     mat.resize(m, vector<double>(n));
//     for (int i = 0; i < m; i++)
//         for (int j = 0; j < n; j++)
//             fin >> mat[i][j];
// }

// void multiplyRows(const Matrix &A, const Matrix &B, Matrix &C, int start, int end) {
//     int m = A.size(), n = B[0].size(), p = B.size();
//     for (int i = start; i < end; i++){
//         for (int j = 0; j < n; j++){
//             double sum = 0;
//             for (int k = 0; k < p; k++){
//                 sum += A[i][k] * B[k][j];
//             }
//             C[i][j] = sum;
//         }
//     }
// }

// void thresholdOperation(Matrix &M, int start, int end, double threshold) {
//     int cols = M[0].size();
//     for (int i = start; i < end; i++){
//         for (int j = 0; j < cols; j++){
//             if (M[i][j] < threshold)
//                 M[i][j] = 0;
//         }
//     }
// }

// int main(){
//     Matrix A, B;
//     readMatrix("matrixA.txt", A);
//     readMatrix("matrixB.txt", B);
//     int m = A.size(), n = B[0].size();
//     Matrix product(m, vector<double>(n, 0));

//     // Matrix multiplication with threads (each thread handles a subset of rows)
//     int numThreads = 4;
//     vector<thread> threads;
//     int rowsPerThread = m / numThreads;
//     for (int t = 0; t < numThreads; t++){
//         int start = t * rowsPerThread;
//         int end = (t == numThreads - 1) ? m : start + rowsPerThread;
//         threads.emplace_back(multiplyRows, cref(A), cref(B), ref(product), start, end);
//     }
//     for (auto &t : threads)
//         t.join();

//     // Element-wise threshold operation (for example, set values below 10 to 0)
//     double threshold = 10.0;
//     threads.clear();
//     for (int t = 0; t < numThreads; t++){
//         int start = t * rowsPerThread;
//         int end = (t == numThreads - 1) ? m : start + rowsPerThread;
//         threads.emplace_back(thresholdOperation, ref(product), start, end, threshold);
//     }
//     for (auto &t : threads)
//         t.join();

//     cout << "Modified Product Matrix:\n";
//     for (auto &row : product){
//         for (auto val : row)
//             cout << val << " ";
//         cout << "\n";
//     }
//     return 0;
// }


