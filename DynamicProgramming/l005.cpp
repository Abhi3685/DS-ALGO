#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void paintHouse(vector<vector<int>>& arr, int n) {
  int red = arr[0][0];
  int blue = arr[0][1];
  int green = arr[0][2];

  for (int i = 1; i < n; i++) {
    int nred = arr[i][0] + min(blue, green);
    int nblue = arr[i][1] + min(red, green);
    int ngreen = arr[i][2] + min(red, blue);

    red = nred;
    blue = nblue;
    green = ngreen;
  }

  cout << min(red, min(blue, green)) << endl;
}

void tiling2x1(int n) {
  vector<int> dp(n + 1);
  dp[1] = 1;
  dp[2] = 2;
  
  for (int i = 3; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  cout << dp[n] << endl;
}

void tilingMx1(int n , int m) {
  vector<int> dp(n + 1);
  dp[1] = 1;
  
  for (int i = 2; i <= n; i++) {
    if (i < m) {
      dp[i] = 1;
    } else if (i == m) {
      dp[i] = 2;
    } else {
      dp[i] = dp[i - 1] + dp[i - m];
    }
  }

  cout << dp[n] << endl;
}

void friendsPairing(int n) {
  if (n <= 2) {
    cout << n << endl;
    return;
  }

  vector<int> arr(n + 1);
  arr[0] = 0;
  arr[1] = 1;
  arr[2] = 2;

  for (int i = 3; i <= n; i++) {
    arr[i] = arr[i - 1] + (i - 1) * arr[i - 2];
  }

  cout << arr[n] << endl;
}

int main() {
  int n = 4;
  vector<vector<int>> arr = {
    {1, 5, 7},
    {5, 8, 4},
    {3, 2, 9},
    {1, 2, 4}
  };

  paintHouse(arr, n);

  tiling2x1(8);
  tilingMx1(39, 16);

  friendsPairing(4);

  return 0;
}