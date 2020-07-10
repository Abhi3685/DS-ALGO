#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> isPalindromicSubstring(string str) {
  vector<vector<bool>> dp(str.length(), vector<bool>(str.length()));
  for(int gap=0; gap<str.length(); gap++){
    for(int si=0, ei=gap; ei<str.length(); si++, ei++) {
      if(gap == 0) dp[si][ei] = true;
      else if(gap == 1 && str[si] == str[ei]) dp[si][ei] = true;
      else dp[si][ei] = (str[si] == str[ei]) && dp[si+1][ei-1]; 
    }
  }
  return dp;
}

int longestPalindromicSubstring(string str) {
  vector<vector<int>> dp(str.length(), vector<int>(str.length()));
  int maxLength = 0;
  for(int gap=0; gap<str.length(); gap++){
    for(int si=0, ei=gap; ei<str.length(); si++, ei++) {
      if(gap == 0) dp[si][ei] = 1;
      else if(gap == 1 && str[si] == str[ei]) dp[si][ei] = 2;
      else if(str[si] == str[ei] && dp[si+1][ei-1] != 0) dp[si][ei] = dp[si+1][ei-1] + 2; 

      maxLength = max(maxLength, dp[si][ei]);
    }
  }
  return maxLength;
}

int longestPalindromicSubsequence(string str) {
  vector<vector<int>> dp(str.length(), vector<int>(str.length()));
  for(int gap=0; gap<str.length(); gap++){
    for(int si=0, ei=gap; ei<str.length(); si++, ei++) {
      if(gap == 0) dp[si][ei] = 1;
      else if(gap == 1 && str[si] == str[ei]) dp[si][ei] = 2;
      else if(str[si] == str[ei] && dp[si+1][ei-1] != 0) dp[si][ei] = dp[si+1][ei-1] + 2; 
      else dp[si][ei] = max(dp[si+1][ei], dp[si][ei-1]);
    }
  }
  return dp[0][str.length() - 1];
}

int countOfPalindromicSubstring(string str) {
  int count = 0;
  vector<vector<bool>> dp(str.length(), vector<bool>(str.length()));
  for(int gap=0; gap<str.length(); gap++){
    for(int si=0, ei=gap; ei<str.length(); si++, ei++) {
      if(gap == 0) { count++; dp[si][ei] = true; }
      else if(gap == 1 && str[si] == str[ei]) { count++; dp[si][ei] = true; }
      else if(str[si] == str[ei] && dp[si+1][ei-1]) { count++; dp[si][ei] = true; } 
    }
  }
  return count;
}

int countOfPalindromicSubsequence(string str) {
  vector<vector<int>> dp(str.length(), vector<int>(str.length()));
  for(int gap=0; gap<str.length(); gap++){
    for(int si=0, ei=gap; ei<str.length(); si++, ei++) {
      if(gap == 0) dp[si][ei] = 1;
      else if(str[si] == str[ei]) dp[si][ei] = dp[si+1][ei] + dp[si][ei-1] + 1; 
      else dp[si][ei] = dp[si+1][ei] + dp[si][ei-1] - dp[si+1][ei-1];
    }
  }
  return dp[0][str.length() - 1];
}

int main() {
  // Question 1
  vector<vector<bool>> dp = isPalindromicSubstring("abbc");
  for(auto a: dp) {
    for(auto b: a){
      if(b) cout << "T ";
      else cout << "F ";
    }
    cout << endl;
  }

  // Question 2
  int ans = longestPalindromicSubstring("abccbdef");
  cout << ans << endl;

  // Question 3
  ans = longestPalindromicSubsequence("GEEKSFORGEEKS");
  cout << ans << endl;

  // Question 4
  cout << countOfPalindromicSubstring("abccba") << endl;

  // Question 5
  cout << countOfPalindromicSubsequence("baccbab") << endl;

  return 0;
}