#include <iostream>
#include <vector>
#include <queue>
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

void leet207(int numOfCourses, vector<vector<int>> &prereq)
{
    vector<vector<int>> graph(numOfCourses, vector<int>());
    for (vector<int> edge : prereq)
    {
        int u = edge[0], v = edge[1];
        graph[u].push_back(v);
    }

    vector<int> incidentEdges(numOfCourses, 0);
    for (int i = 0; i < numOfCourses; i++)
    {
        for (int vtx : graph[i])
            incidentEdges[vtx]++;
    }

    queue<int> que, ans;
    for (int i = 0; i < numOfCourses; i++)
    {
        if (incidentEdges[i] == 0)
            que.push(i);
    }

    while (que.size() != 0)
    {
        int vtx = que.front();
        que.pop();

        ans.push(vtx);
        for (int nbr : graph[vtx])
        {
            if (--incidentEdges[nbr] == 0)
            {
                que.push(nbr);
            }
        }
    }

    if (ans.size() != graph.size())
        cout << "false" << endl;
    else
        cout << "true" << endl;
}

void leet210(int numOfCourses, vector<vector<int>> &prereq)
{
    vector<vector<int>> graph(numOfCourses, vector<int>());
    for (vector<int> edge : prereq)
    {
        int u = edge[0], v = edge[1];
        graph[u].push_back(v);
    }

    vector<int> incidentEdges(numOfCourses, 0);
    for (int i = 0; i < numOfCourses; i++)
    {
        for (int vtx : graph[i])
            incidentEdges[vtx]++;
    }

    queue<int> que, ans;
    for (int i = 0; i < numOfCourses; i++)
    {
        if (incidentEdges[i] == 0)
            que.push(i);
    }

    while (que.size() != 0)
    {
        int vtx = que.front();
        que.pop();

        ans.push(vtx);
        for (int nbr : graph[vtx])
        {
            if (--incidentEdges[nbr] == 0)
            {
                que.push(nbr);
            }
        }
    }

    if (ans.size() != graph.size())
        cout << "-1" << endl;
    else
    {
        vector<int> myAns(numOfCourses);
        int i = numOfCourses - 1;
        while (ans.size() != 0)
        {
            myAns[i--] = ans.front();
            ans.pop();
        }

        for (int n : myAns)
            cout << n << " ";
        cout << endl;
    }
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

    // ============ Leetcode 207 ================
    vector<vector<int>> prerequisites = {
        {1, 0}};
    leet207(2, prerequisites);
    leet210(2, prerequisites);

    return 0;
}