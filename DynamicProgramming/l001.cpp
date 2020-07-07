#include <iostream>
#include <vector>
using namespace std;

// Utility Functions
void display2D(vector<vector<int>> &arr) {
  for (auto ar: arr) {
    for (int ele: ar)
      cout << ele << " ";
    cout << endl;
  }
}

void display(vector<int> &arr) {
  for (int ele: arr) 
    cout << ele << " ";
  cout << endl;
}

// Fibonacci Problem Memoization
int fib_01(int n, vector<int> &dp) {
  if (n <= 1) 
    return dp[n] = n;

  if (dp[n] != 0) return dp[n];
  int ans = fib_01(n - 1, dp) + fib_01(n - 2, dp);
  return dp[n] = ans;
}

// Fibonacci Problem Tabulation
int fibDP_01(int N, vector<int> &dp) {
  for (int n = 0; n <= N; n++) {
    if (n <= 1) {
      dp[n] = n;
      continue;
    }
    dp[n] = dp[n - 1] + dp[n - 2];
  }
  return dp[N];
}

// Fibonacci Problem Constant Space
int fibDPExtend_01(int N) {
  int a = 0, b = 1, c;
  for (int n = 0; n <= N; n++) {
    if (n <= 1)
      continue;

    c = a + b;
    a = b;
    b = c;
  }
  return c;
}

void basic() {
  int n = 7, ans;
  vector<int> dp(n + 1);

  ans = fib_01(n, dp);
  ans = fibDP_01(n,dp);

  display(dp);
  cout << ans << endl;
}

int mazePathHVD_rec(int sr, int sc, int er, int ec, vector<vector<int>> &dp) {
  if (sr == er && sc == ec) 
    return dp[sr][sc] = 1;

  if (dp[sr][sc] != 0) return dp[sr][sc];

  int count = 0;
  if (sr + 1 <= er)
    count += mazePathHVD_rec(sr + 1, sc, er, ec, dp);
  if (sr + 1 <= er && sc + 1 <= ec)
    count += mazePathHVD_rec(sr + 1, sc + 1, er, ec, dp);
  if (sc + 1 <= ec)
    count += mazePathHVD_rec(sr, sc + 1, er, ec, dp);

  return dp[sr][sc] = count;
}

int mazePathHV_DP(int sr, int sc, int er, int ec, vector<vector<int>> &dp) {
  for (sr = er; sr >= 0; sr--) {
    for (sc = ec; sc >= 0; sc--) {
      if (sr == er && sc == ec) {
        dp[sr][sc] = 1;
        continue;
      }

      int count = 0;
      if (sr + 1 <= er)
        count += dp[sr + 1][sc];

      if (sr + 1 <= er && sc + 1 <= ec)
        count += dp[sr + 1][sc + 1];

      if (sc + 1 <= ec)
        count += dp[sr][sc + 1];

      dp[sr][sc] = count;
    }
  }
  return dp[0][0];
}

int mazePathMulti_rec(int sr, int sc, int er, int ec, vector<vector<int>> &dp) {
  if (sr == er && sc == ec)
    return dp[sr][sc] = 1;

  if (dp[sr][sc] != 0) return dp[sr][sc];

  int count = 0;
  for (int jump = 1; sr + jump <= er; jump++)
    count += mazePathMulti_rec(sr + jump, sc, er, ec, dp);

  for (int jump = 1; sr + jump <= er && sc + jump <= ec; jump++)
    count += mazePathMulti_rec(sr + jump, sc + jump, er, ec, dp);

  for (int jump = 1; sc + jump <= ec; jump++)
    count += mazePathMulti_rec(sr, sc + jump, er, ec, dp);

  return dp[sr][sc] = count;
}

int mazePathMulti_DP(int sr, int sc, int er, int ec, vector<vector<int>> &dp) {
  for(sr = er; sr >= 0; sr--){
    for(sc = ec; sc >= 0; sc--){
      if (sr == er && sc == ec) {
          dp[sr][sc] = 1;
          continue;
      }

      int count = 0;
      for (int jump = 1; sr + jump <= er; jump++)
        count += dp[sr + jump][sc];

      for (int jump = 1; sr + jump <= er && sc + jump <= ec; jump++)
        count += dp[sr + jump][sc + jump];

      for (int jump = 1; sc + jump <= ec; jump++)
        count += dp[sr][sc + jump];

      dp[sr][sc] = count;
    }
  }
  return dp[0][0];
}

void PathSeries() {
  int sr = 0, sc = 0;
  int er = 3, ec = 3;
	int ans = 0;
	vector<vector<int>> dp(er + 1, vector<int>(ec + 1));
      
  ans = mazePathHVD_rec(sr, sc, er, ec, dp);
  ans = mazePathMulti_rec(sr, sc, er, ec, dp);
  ans = mazePathMulti_DP(sr, sc, er, ec, dp);

  display2D(dp);
  cout << ans << endl;
}

void Solve() {
  // basic();
  PathSeries();
}

int main() {
  Solve();
  return 0;
}