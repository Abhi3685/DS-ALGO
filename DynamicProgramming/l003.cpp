#include <iostream>
#include <vector>
using namespace std;

int getMaxGold(vector<vector<int>> &gold, int sr, int sc, vector<vector<int>> &dp) {
  if(sc == gold[0].size() - 1){
    return dp[sr][sc] = gold[sr][sc];
  }
  
  if(dp[sr][sc] != 0) return dp[sr][sc];
  
  int cost = 0;
  if(sr - 1 >= 0) {
    cost = max(cost, getMaxGold(gold, sr - 1, sc + 1, dp));
  }
  cost = max(cost, getMaxGold(gold, sr, sc + 1, dp));
  if(sr + 1 < gold.size()) {
    cost = max(cost, getMaxGold(gold, sr + 1, sc + 1, dp));
  }

  return dp[sr][sc] = cost + gold[sr][sc];
}

int getMaxGold_DP(vector<vector<int>> &gold, vector<vector<int>> &dp) {
  for(int sc=gold[0].size()-1; sc>=0; sc--) {
    for(int sr=gold.size()-1; sr>=0; sr--) {
      if(sc == gold[0].size() - 1){
        dp[sr][sc] = gold[sr][sc];
        continue;
      }
      
      int cost = 0;
      if(sr - 1 >= 0) {
        cost = max(cost, dp[sr - 1][sc + 1]);
      }
      cost = max(cost, dp[sr][sc + 1]);
      if(sr + 1 < gold.size()) {
        cost = max(cost, dp[sr + 1][sc + 1]);
      }
      dp[sr][sc] = cost + gold[sr][sc];
    }
  }
  
  int overallAns = 0;
  for(int i=0; i<dp.size(); i++){
    if(dp[i][0] > overallAns) overallAns = dp[i][0];
  }
  return overallAns;
}

int findWaysToPair(int n, vector<int> &dp) {
  if(n <= 2) return dp[n] = n;
  
  if(dp[n] != 0) return dp[n];

  int singleWays = findWaysToPair(n - 1, dp);
  int pairWays = (n - 1) * findWaysToPair(n - 2, dp);
  return dp[n] = singleWays + pairWays;
}

int findWaysToPair_DP(int n, vector<int> &dp) {
  dp[1] = 1;
  dp[2] = 2;

  for(int i = 3; i <= n; i++) {
    dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
  }

  return dp[n];
}

int findWaysToPair_FibApproach(int n) {
  int a = 1;
  int b = 2;

  for(int i = 3; i <= n; i++) {
    int c = b + (i - 1) * a;
    a = b;
    b = c;
  }
  
  return b;
}

int countP(int n, int k, vector<vector<int>> &dp) {
  if (n == 0 || k == 0 || k > n) return dp[n][k] = 0;
  if (k == 1 || k == n) return dp[n][k] = 1;

  if(dp[n][k] != 0) return dp[n][k];

  int newCall = countP(n - 1, k - 1, dp);
  int partCall = countP(n - 1, k, dp);
  return dp[n][k] = k * partCall + newCall;
}

int countP_DP(int N, int K, vector<vector<int>> &dp) {
  for(int n=0; n<=N; n++) {
    for(int k=0; k<=K; k++) {
      if (n == 0 || k == 0 || k > n) { dp[n][k] = 0; continue; }
      if (k == 1 || k == n) { dp[n][k] = 1; continue; }

      int newCall = dp[n - 1][k - 1];
      int partCall = dp[n - 1][k];
      dp[n][k] = k * partCall + newCall;
    }
  }
  return dp[N][K];
}

int main() {
  // ====================== Gold Mine Problem ========================
  // vector<vector<int>> gold = { 
  //   {1, 3, 1, 5}, 
  //   {2, 2, 4, 1}, 
  //   {5, 0, 2, 3}, 
  //   {0, 6, 1, 2} 
  // }; 
  // vector<vector<int>> dp(gold.size(), vector<int>(gold[0].size()));
  
  // int overallAns = 0;
  // for(int i=0; i<gold.size(); i++){
  //   int ans = getMaxGold(gold, i, 0, dp);
  //   if(ans > overallAns) overallAns = ans;
  // }
  // cout << overallAns << endl;

  // int ans = getMaxGold_DP(gold, dp);
  // cout << ans << endl;
  // =================================================================

  // ================= No. of ways to pair people ===================
  // int n = 10, ans;
  // vector<int> dp(n+1);
  // ans = findWaysToPair(n, dp);
  // cout << ans << endl;

  // ans = findWaysToPair_DP(n, dp);
  // cout << ans << endl;

  // ans = findWaysToPair_FibApproach(n);
  // cout << ans << endl;
  // =================================================================

  // ======== No. of ways to partition a set into k subsets ==========
  int n = 5, k = 3, ans;
  vector<vector<int>> dp(n+1, vector<int>(k+1));
  ans = countP(n, k, dp);
  cout << ans << endl;
  for(auto ar: dp){
    for(int ele: ar)
      cout << ele << " ";
    cout << endl;
  }

  ans = countP_DP(n, k, dp);
  cout << ans << endl;
  // =================================================================

  return 0;
}