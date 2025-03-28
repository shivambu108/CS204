#include <iostream>
#include <vector>
#include <thread>
using namespace std;

void addRow(const vector<vector<int>> &A, const vector<vector<int>> &B,
            vector<vector<int>> &C, int row) {
    for (size_t j = 0; j < A[0].size(); ++j)
        C[row][j] = A[row][j] + B[row][j];
}

int main() {
    int rows = 3, cols = 3;
    vector<vector<int>> A = { {1,2,3}, {4,5,6}, {7,8,9} };
    vector<vector<int>> B = { {9,8,7}, {6,5,4}, {3,2,1} };
    vector<vector<int>> C(rows, vector<int>(cols, 0));

    vector<thread> threads;
    for (int i = 0; i < rows; i++){
        threads.emplace_back(addRow, cref(A), cref(B), ref(C), i);
    }
    for(auto &t : threads)
        t.join();

    cout << "Matrix Addition Result:\n";
    for(auto &row: C){
        for(auto val: row)
            cout << val << " ";
        cout << "\n";
    }
    return 0;
}
