#include <iostream>
#include <vector>
using namespace std;

void queenComb(int boxsize, int noq, string ans, int idx) {
    if(noq == 0) {
        cout << ans << endl;
        return;
    }
    if(idx >= boxsize) return;
    queenComb(boxsize, noq - 1, ans + "b" + to_string(idx) + "q" + to_string(noq) + " ", idx + 1);
    queenComb(boxsize, noq, ans, idx + 1);
}

void queenPer(int boxsize, int noq, string ans, int idx, vector<bool> &vis) {
    if(noq == 0) {
        cout << ans << endl;
        return;
    }
    if(idx >= boxsize) return;
    if(!vis[idx]) {
        vis[idx] = true;
        queenPer(boxsize, noq - 1, ans + "b" + to_string(idx) + "q" + to_string(noq) + " ", 0, vis);
        vis[idx] = false;
    }
    queenPer(boxsize, noq, ans, idx + 1, vis);
}

void queenComb2D(int boxsize, int noq, string ans, int idx) {
    if(noq == 0) {
        cout << ans << endl;
        return;
    }
    if(idx >= boxsize * boxsize) return;

    int x = idx / boxsize;
    int y = idx % boxsize;
    queenComb2D(boxsize, noq - 1, ans + "(" + to_string(x) + ", " + to_string(y) + ") ", idx + 1);
    queenComb2D(boxsize, noq, ans, idx + 1);
}

void queenPer2D(int boxsize, int noq, string ans, int idx, vector<bool> &vis) {
    if(noq == 0) {
        cout << ans << endl;
        return;
    }
    if(idx >= boxsize * boxsize) return;

    int x = idx / boxsize;
    int y = idx % boxsize;
    if(!vis[idx]) {
        vis[idx] = true;
        queenPer2D(boxsize, noq - 1, ans + "(" + to_string(x) + ", " + to_string(y) + ") ", 0, vis);
        vis[idx] = false;
    }
    queenPer2D(boxsize, noq, ans, idx + 1, vis);
}

bool safeToPlaceQueen(vector<vector<bool>> &box, int x, int y) {
    vector<vector<int>> dir = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1} };
    for(int d = 0; d < dir.size(); d++) {
        for(int rad = 1; rad < box.size(); rad++) {
            int r = x + rad*dir[d][0];
            int c = y + rad*dir[d][1];
            if(r >= 0 && c >= 0 && r < box.size() && c < box[0].size()) {
                if(box[r][c])
                    return false;
            }
        }
    }
    return true;
}

void nQueen(vector<vector<bool>> &box, int noq, string ans, int idx) {
    if(noq == 0) {
        cout<<ans<<endl;
        return;
    }
    for(int i = idx; i < box.size() * box.size(); i++) {
        int x = i / box.size();
        int y = i % box.size();
        if(safeToPlaceQueen(box, x, y)) {
            box[x][y] = true;
            nQueen(box, noq - 1, ans + "(" + to_string(x) + ", " + to_string(y) + ") ", i + 1);
            box[x][y] = false;
        }
    }
}

void nQueen_01(vector<vector<bool>> &box, int noq, string ans, int row) {
    if(noq == 0) {
        cout<<ans<<endl;
        return;
    }
    for(int col = 0; col < box[0].size(); col++) {
        if(safeToPlaceQueen(box, row, col)) {
            box[row][col] = true;
            nQueen_01(box, noq - 1, ans + "(" + to_string(row) + ", " + to_string(col) + ") ", row + 1);
            box[row][col] = false;
        }
    }
}

void nQueen_02(vector<vector<bool>> &box, vector<bool> &row, vector<bool> &col, vector<bool> &diag1, vector<bool> &diag2, string ans, int noq, int currRow) {
    if(noq == 0) {
        cout<<ans<<endl;
        return;
    }
    for(int currCol = 0; currCol < box[0].size(); currCol++) {
        if(!row[currRow] && !col[currCol] && !diag1[currRow - currCol + (col.size() - 1)] && !diag2[currRow + currCol]) {
            row[currRow] = true;
            col[currCol] = true;
            diag1[currRow - currCol + (col.size() - 1)] = true;
            diag2[currRow + currCol] = true;
            nQueen_02(box, row, col, diag1, diag2, ans + "(" + to_string(currRow) + ", " + to_string(currCol) + ") ", noq - 1, currRow + 1);
            row[currRow] = false;
            col[currCol] = false;
            diag1[currRow - currCol + (col.size() - 1)] = false;
            diag2[currRow + currCol] = false;
        }
    }
}

void solve() {
    // Given an array of size n, we have to find all combinations
    // of placing m queens in that array
    // queenComb(5, 3, "", 0);

    // Given an array of size n, we have to find all permutations
    // of placing m queens in that array
    // vector<bool> vis(5, false);
    // queenPer(5, 3, "", 0, vis);

    // Given a 2D array of size n*n, we have to find all combinations
    // of placing n queens in that array
    // queenComb2D(4, 4, "", 0);

    // Given a 2D array of size n*n, we have to find all permutations
    // of placing n queens in that array
    // vector<bool> vis(5, false);
    // queenPer2D(4, 4, "", 0, vis);

    // N Queen Problem
    // vector<vector<bool>> box(4, vector<bool>(4, false));
    // nQueen(box, 4, "", 0);

    // N Queen Problem (Optimise #1)
    // vector<vector<bool>> box(4, vector<bool>(4, false));
    // nQueen_01(box, 4, "", 0);

    // N Queen Problem (Optimise #2)
    // vector<vector<bool>> box(4, vector<bool>(4, false));
    // vector<bool> row(4, false);
    // vector<bool> col(4, false);
    // vector<bool> diag1(7, false); // row + col - 1
    // vector<bool> diag2(7, false);
    // nQueen_02(box, row, col, diag1, diag2, "", 4, 0);
}

int main() {
    solve();
    return 0;
}