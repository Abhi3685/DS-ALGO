#include <iostream>
#include <vector>
using namespace std;

void leet130_util(vector<vector<char>> &board, int x, int y)
{
    if (board[x][y] == 'X')
        return;

    board[x][y] = '#';

    if (x - 1 >= 0)
        leet130_util(board, x - 1, y);
    if (y - 1 >= 0)
        leet130_util(board, x, y - 1);
    if (x + 1 < board.size())
        leet130_util(board, x + 1, y);
    if (y + 1 < board[0].size())
        leet130_util(board, x, y + 1);
}

void leet130(vector<vector<char>> &board)
{
    int r = board.size();
    int c = board[0].size();

    for (int i = 0; i < r; i++)
    {
        if (board[i][0] == 'O')
            leet130_util(board, i, 0);
        if (board[i][c - 1] == 'O')
            leet130_util(board, i, c - 1);
    }

    for (int j = 0; j < c; j++)
    {
        if (board[0][j] == 'O')
            leet130_util(board, 0, j);
        if (board[r - 1][j] == 'O')
            leet130_util(board, r - 1, j);
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == '#')
                board[i][j] = 'O';
            else if (board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
}

void leet1267(vector<vector<int>> &grid)
{
    vector<int> row(grid.size(), 0);
    vector<int> col(grid[0].size(), 0);

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                row[i]++;
                col[j]++;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1))
                ans++;
        }
    }

    cout << ans << endl;
}

int main()
{
    // ============ Leetcode 130 ================
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
    };
    leet130(board);
    for (auto v : board)
    {
        for (auto n : v)
            cout << n << " ";
        cout << endl;
    }

    // ============ Leetcode 1267 ================
    vector<vector<int>> grid = {
        {1, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
    };
    leet1267(grid);

    return 0;
}