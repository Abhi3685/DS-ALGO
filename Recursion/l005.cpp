#include <iostream>
#include <vector>
using namespace std;

void nQueen_03(int boxsize, int row, int col, int diag1, int diag2, int noq, string ans, int currRow) {
    if(noq == 0) {
        cout << ans << endl;
        return;
    }
    for(int currCol = 0; currCol < boxsize; currCol++) {
        int rowMask = 1 << currRow;
        int colMask = 1 << currCol;
        int diag1Mask = 1 << currRow - currCol + (boxsize - 1);
        int diag2Mask = 1 << currRow + currCol;

        // Checking if is safe to place queen by checking corresponding bits
        if((row & rowMask) == 0 && (col & colMask) == 0 && (diag1 & diag1Mask) == 0 && (diag2 & diag2Mask) == 0) {
            // Setting bit to 1
            row |= rowMask;
            col |= colMask;
            diag1 |= diag1Mask;
            diag2 |= diag2Mask;
            nQueen_03(boxsize, row, col, diag1, diag2, noq - 1, ans + "(" + to_string(currRow) + ", " + to_string(currCol) + ") ", currRow + 1);
            // Setting bit to 0 (Backtrack)
            row &= (~rowMask);
            col &= (~colMask);
            diag1 &= (~diag1Mask);
            diag2 &= (~diag2Mask);
        }
    }
}

bool isSafeToPlaceNumber(vector<vector<int>> &box, int num, int x, int y) {
    for(int i = 0; i < 9; i++) {
        if(box[i][y] == num) return false;
    }
    for(int i = 0; i < 9; i++) {
        if(box[x][i] == num) return false;
    }
    int boxStartR = x - x % 3;
    int boxStartC = y - y % 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(box[boxStartR + i][boxStartC + j] == num) return false;
        }
    }
    return true;
}

void sudoku(vector<vector<int>> &box, int idx) {
    if(idx == 81) {
        // Printing Solved Sudoku Box
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << box[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    int x = idx / 9, y = idx % 9;
    if(box[x][y] == 0) {
        for(int n = 1; n <= 9; n++) {
            if(isSafeToPlaceNumber(box, n, x, y)){
                box[x][y] = n;
                sudoku(box, idx + 1);
                box[x][y] = 0;
            }
        }
    } else {
        sudoku(box, idx + 1);
    }
}

void sudoku_01(vector<vector<int>> &box, vector<int> &calls, int idx) {
    if(idx == calls.size()) {
        // Printing Solved Sudoku Box
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << box[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    int x = calls[idx] / 9, y = calls[idx] % 9;
    for(int n = 1; n <= 9; n++) {
        if(isSafeToPlaceNumber(box, n, x, y)){
            box[x][y] = n;
            sudoku_01(box, calls, idx + 1);
            box[x][y] = 0;
        }
    }
}

void sudoku_02(vector<vector<int>> &box, vector<int> &calls, int idx, vector<int> &row, vector<int> &col, vector<vector<int>> &mat) {
    if(idx == calls.size()) {
        // Printing Solved Sudoku Box
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << box[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    int x = calls[idx] / 9, y = calls[idx] % 9;
    for(int n = 1; n <= 9; n++) {
        int mask = 1 << n;
        if((row[x] & mask) == 0 && (col[y] & mask) == 0 && (mat[x/3][y/3] & mask) == 0){
            box[x][y] = n;
            row[x] ^= mask;
            col[y] ^= mask;
            mat[x/3][y/3] ^= mask;
            sudoku_02(box, calls, idx + 1, row, col, mat);
            box[x][y] = 0;
            row[x] ^= mask;
            col[y] ^= mask;
            mat[x/3][y/3] ^= mask;
        }
    }
}

void solve() {
    // N Queen Optimization using Bit Manipulation Approach
    // nQueen_03(4, 0, 0, 0, 0, 4, "", 0);

    // Sudoku #1 Basic Approach
    // vector<vector<int>> box = {
    //     {0, 0, 6, 5, 0, 8, 4, 0, 0},  
    //     {5, 2, 0, 0, 0, 0, 0, 0, 0},  
    //     {0, 8, 7, 0, 0, 0, 0, 3, 1},  
    //     {0, 0, 3, 0, 1, 0, 0, 8, 0},  
    //     {9, 0, 0, 8, 6, 3, 0, 0, 5},  
    //     {0, 5, 0, 0, 9, 0, 6, 0, 0},  
    //     {1, 3, 0, 0, 0, 0, 2, 5, 0},  
    //     {0, 0, 0, 0, 0, 0, 0, 7, 4},  
    //     {0, 0, 5, 2, 0, 6, 3, 0, 0}
    // }; 
    // sudoku(box, 0);

    // Sudoku #2 Optimized Approach
    // vector<vector<int>> box = {
    //     {0, 0, 6, 5, 0, 8, 4, 0, 0},  
    //     {5, 2, 0, 0, 0, 0, 0, 0, 0},  
    //     {0, 8, 7, 0, 0, 0, 0, 3, 1},  
    //     {0, 0, 3, 0, 1, 0, 0, 8, 0},  
    //     {9, 0, 0, 8, 6, 3, 0, 0, 5},  
    //     {0, 5, 0, 0, 9, 0, 6, 0, 0},  
    //     {1, 3, 0, 0, 0, 0, 2, 5, 0},  
    //     {0, 0, 0, 0, 0, 0, 0, 7, 4},  
    //     {0, 0, 5, 2, 0, 6, 3, 0, 0}
    // }; 
    // vector<int> calls;
    // for(int i = 0; i < 9; i++) {
    //     for(int j = 0; j < 9; j++) {
    //         if(box[i][j] == 0)
    //             calls.push_back(i * 9 + j);
    //     }
    // }
    // sudoku_01(box, calls, 0);

    // Sudoku #3 Optimization using Bit Manipulation Approach
    // vector<vector<int>> box = {
    //     {0, 0, 6, 5, 0, 8, 4, 0, 0},  
    //     {5, 2, 0, 0, 0, 0, 0, 0, 0},  
    //     {0, 8, 7, 0, 0, 0, 0, 3, 1},  
    //     {0, 0, 3, 0, 1, 0, 0, 8, 0},  
    //     {9, 0, 0, 8, 6, 3, 0, 0, 5},  
    //     {0, 5, 0, 0, 9, 0, 6, 0, 0},  
    //     {1, 3, 0, 0, 0, 0, 2, 5, 0},  
    //     {0, 0, 0, 0, 0, 0, 0, 7, 4},  
    //     {0, 0, 5, 2, 0, 6, 3, 0, 0}
    // };
    // vector<int> calls;
    // vector<int> row(9, 0);
    // vector<int> col(9, 0);
    // vector<vector<int>> mat(3, vector<int>(3, 0));
    // for(int i = 0; i < 9; i++) {
    //     for(int j = 0; j < 9; j++) {
    //         if(box[i][j] == 0)
    //             calls.push_back(i * 9 + j);
    //         else {
    //             int mask = 1 << box[i][j];
    //             row[i] |= mask;
    //             col[j] |= mask;
    //             mat[i/3][j/3] |= mask;
    //         }
    //     }
    // }
    // sudoku_02(box, calls, 0, row, col, mat);
}

int main() {
    solve();
    return 0;
}