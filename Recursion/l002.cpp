#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isLocSafe(vector<vector<bool>> &board, int x, int y) {
    if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y])
        return false;
    return true;
}

bool isRatLocSafe(vector<vector<int>> &board, int x, int y) {
    if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y] == 0)
        return false;
    return true;
}

bool isKnightLocSafe(vector<vector<int>> &board, int x, int y) {
    if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y] != 0)
        return false;
    return true;
}

bool isIsland(vector<vector<int>> &board, int x, int y) {
    if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y] == 0)
        return false;
    return true;
}

vector<string> floodfill(int sr, int sc, int er, int ec, vector<vector<bool>> &board, vector<vector<int>> &dir, vector<string> &path) {
    if(sr == er && sc == ec) {
        vector<string> base;
        base.push_back("");
        return base;
    }
    vector<string> myAns;
    for(int i=0; i<dir.size(); i++) {
        int x = sr + dir[i][0];
        int y = sc + dir[i][1];
        if(isLocSafe(board, x, y)) {
            board[sr][sc] = true;
            vector<string> recAns = floodfill(x, y, er, ec, board, dir, path);
            for(string s: recAns) myAns.push_back(s + path[i]);
            board[sr][sc] = false;
        }
    }
    return myAns;
}

vector<string> ratInMaze(int sr, int sc, int er, int ec, vector<vector<int>> &board, vector<vector<int>> &dir, vector<string> &path) {
    if(sr == er && sc == ec) {
        vector<string> base;
        base.push_back("");
        return base;
    }
    vector<string> myAns;
    for(int i=0; i<dir.size(); i++) {
        int x = sr + dir[i][0];
        int y = sc + dir[i][1];
        if(isRatLocSafe(board, x, y)) {
            board[sr][sc] = 0;
            vector<string> recAns = ratInMaze(x, y, er, ec, board, dir, path);
            for(string s: recAns) myAns.push_back(path[i] + s);
            board[sr][sc] = 1;
        }
    }
    return myAns;
}

bool knightTour(int sr, int sc, vector<vector<int>> &board, vector<vector<int>> &dir, int move) {
    if(move == 64) {
        return true;
    }
    for(int i=0; i<dir.size(); i++) {
        int x = sr + dir[i][0];
        int y = sc + dir[i][1];
        if(isKnightLocSafe(board, x, y)) {
            board[x][y] = move + 1;
            bool isSuccess = knightTour(x, y, board, dir, move + 1);
            if(isSuccess) return true;
            board[x][y] = 0;
        }
    }
}

vector<string> floodfillVariableJump(int sr, int sc, int er, int ec, vector<vector<bool>> &board, vector<vector<int>> &dir, vector<string> &path) {
    if(sr == er && sc == ec) {
        vector<string> base;
        base.push_back("");
        return base;
    }
    vector<string> myAns;
    for(int i=0; i<dir.size(); i++) {
        for(int j=1; j<board.size(); j++) {
            int x = sr + j*dir[i][0];
            int y = sc + j*dir[i][1];
            if(isLocSafe(board, x, y)) {
                board[sr][sc] = true;
                vector<string> recAns = floodfillVariableJump(x, y, er, ec, board, dir, path);
                for(string s: recAns) {
                    myAns.push_back(s + to_string(j) + path[i] + " ");
                }
                board[sr][sc] = false;
            }
        }
    }
    return myAns;
}

void islandOcean(int sr, int sc, vector<vector<int>> &board, vector<vector<int>> &dir) {
    if(board[sr][sc] == 0){
        return;
    }
    board[sr][sc] = 0;
    for(int i=0; i<dir.size(); i++) {
        int x = sr + dir[i][0];
        int y = sc + dir[i][1];
        if(isIsland(board, x, y)){
            islandOcean(x, y, board, dir);
        }
    }
}

void solve() {
    /////////////////////////////// FLOOD FILL ////////////////////////////////
    // vector<vector<bool>> board(3, vector<bool>(3, false));
    // vector<vector<int>> dir = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
    // vector<string> path = { "U", "R", "D", "L" };
    // vector<string> ans = floodfill(0, 0, 2, 2, board, dir, path);
    // for(string s: ans) cout << s << endl;

    /////////////////////////////// RAT IN MAZE ////////////////////////////////
    // vector<vector<int>> board = {
    //     { 1, 0, 0, 0 }, 
    //     { 1, 1, 0, 1 }, 
    //     { 1, 1, 0, 0 }, 
    //     { 0, 1, 1, 1 }
    // };
    // vector<vector<int>> dir = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
    // vector<string> path = { "U", "R", "D", "L" };
    // vector<string> ans = ratInMaze(0, 0, 3, 3, board, dir, path);
    // for(string s: ans) cout << s << endl;

    /////////////////////////////// KNIGHT TOUR ////////////////////////////////
    // vector<vector<int>> board(8, vector<int>(8, 0));
    // vector<vector<int>> dir = { { 2, 1 }, { 1, 2 }, { -1, 2 }, { -2, 1 }, { -2, -1 }, { -1, -2 }, { 1, -2 }, { 2, -1 } };
    // board[0][0] = 1;
    // bool isTourSuccess = knightTour(0, 0, board, dir, 1);
    // if(isTourSuccess) { // Print Board
    //     for(int i = 0; i < board.size(); i++) {
    //         for(int j = 0; j < board[0].size(); j++)
    //             cout << board[i][j] << "  ";
    //         cout << endl;
    //     }
    // } else cout << "Something Is Wrong!";

    //////////////////////// FLOOD FILL VARIABLE JUMP /////////////////////////
    // vector<vector<bool>> board(3, vector<bool>(3, false));
    // vector<vector<int>> dir = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
    // vector<string> path = { "U", "R", "D", "L" };
    // vector<string> ans = floodfillVariableJump(0, 0, 2, 2, board, dir, path);
    // for(string s: ans) cout << s << endl;

    /////////////////////// ISLAND OCEAN PROBLEM /////////////////////////////
    // vector<vector<int>> board = {
    //     { 0, 0, 0 }, 
    //     { 1, 1, 1 }, 
    //     { 0, 1, 1 }
    // };
    // vector<vector<int>> dir = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
    // vector<vector<int>> missiles = { { 0, 1 }, { 1, 1 }, { 2, 2 } };
    // for(int i=0 ; i<missiles.size(); i++) {
    //     islandOcean(missiles[i][0], missiles[i][1], board, dir);
    // }
    // for(int i = 0; i < board.size(); i++) {
    //     for(int j = 0; j < board[0].size(); j++)
    //         cout << board[i][j] << "  ";
    //     cout << endl;
    // }
}

int main() {
    solve();
    return 0;
}