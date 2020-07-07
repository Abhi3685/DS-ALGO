#include <iostream>
#include <vector>
using namespace std;

int Q1(vector<int> &moves, int si, int ei, vector<int> &dp) {
  if(si == ei) return dp[si] = 1;

  if(dp[si] != 0) return dp[si];
  
  int count = 0;
  for(int move: moves) {
    if(si + move <= ei) {
      count += Q1(moves, si + move, ei, dp);
    }
  }

  return dp[si] = count;
}

int Q1_DP(vector<int> &moves, int si, int ei, vector<int> &dp) {
  for(int i = ei; i >= si; i--) {        
    if(i == ei) {
      dp[i] = 1;
      continue;
    }

    int count = 0;
    for(int step: moves) {
      if(i + step <= ei) {
        count += dp[i + step];
      }
    }
    dp[i] = count;
  }
  return dp[0];
}

int main() {
  int start = 0, end = 10, ans;
  vector<int> dp(end + 1);

  // Dice Moves
  vector<int> moves = { 1,2,3,4,5,6 };
  ans = Q1(moves, start, end, dp);
  cout << ans << endl;

  // Custom Moves
  moves = { 3,5,7 };
  dp.clear();
  dp.resize(end + 1);
  ans = Q1(moves, start, end, dp);
  cout << ans << endl;

  // Tabulation Approach
  moves = { 1,2,3,4,5,6 };
  ans = Q1_DP(moves, start, end, dp);
  for(int ele: dp) cout << ele << " ";
  cout << endl;
  cout << ans << endl;

  return 0;
}