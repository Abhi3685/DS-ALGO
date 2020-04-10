#include <iostream>
#include <vector>
using namespace std;

void perWithRep(vector<int> &coins, int target, string ans) {
    if(target == 0) {
        cout<<ans<<endl;
        return;
    }
    for(int i=0; i<coins.size(); i++) {
        if(target - coins[i] >= 0){
            perWithRep(coins, target - coins[i], ans + to_string(coins[i]));
        }
    }
}

void perWithoutRep(vector<int>& coins, int target, string ans, vector<bool>& vis) {
    if(target == 0) {
        cout<<ans<<endl;
        return;
    }
    for(int i=0; i<coins.size(); i++) {
        if(target - coins[i] >= 0 && !vis[i]){
            vis[i] = true;
            perWithoutRep(coins, target - coins[i], ans + to_string(coins[i]), vis);
            vis[i] = false;
        }
    }
}

void combWithRep(vector<int> &coins, int target, string ans, int idx) {
    if(target == 0) {
        cout << ans << endl;
        return;
    }
    for(int i=idx; i<coins.size(); i++) {
        if(target - coins[i] >= 0) {
            combWithRep(coins, target - coins[i], ans + to_string(coins[i]), i);
        }
    }
}

void combWithoutRep(vector<int> &coins, int target, string ans, int idx) {
    if(target == 0) {
        cout << ans << endl;
        return;
    }
    for(int i=idx; i<coins.size(); i++) {
        if(target - coins[i] >= 0) {
            combWithRep(coins, target - coins[i], ans + to_string(coins[i]), i + 1);
        }
    }
}

void combWithRepSubseqApproach(vector<int> &coins, int target, string ans, int idx) {
    if(target == 0) {
        cout << ans << endl;
        return;
    }
    if(idx >= coins.size()) return;
    if(target - coins[idx] >= 0) {
        combWithRepSubseqApproach(coins, target - coins[idx], ans + to_string(coins[idx]), idx);
    }
    combWithRepSubseqApproach(coins, target, ans, idx + 1);
}

void combWithoutRepSubseqApproach(vector<int> &coins, int target, string ans, int idx) {
    if(target == 0) {
        cout << ans << endl;
        return;
    }
    if(idx >= coins.size()) return;
    if(target - coins[idx] >= 0) {
        combWithoutRepSubseqApproach(coins, target - coins[idx], ans + to_string(coins[idx]), idx + 1);
    }
    combWithoutRepSubseqApproach(coins, target, ans, idx + 1);
}

void perWithRepSubseqApproach(vector<int> &coins, int target, string ans, int idx) {
    if(target == 0) {
        cout << ans << endl;
        return;
    }
    if(idx >= coins.size()) return;
    if(target - coins[idx] >= 0) {
        perWithRepSubseqApproach(coins, target - coins[idx], ans + to_string(coins[idx]), 0);
    }
    perWithRepSubseqApproach(coins, target, ans, idx + 1);
}

void perWithoutRepSubseqApproach(vector<int> &coins, int target, string ans, vector<bool> &vis, int idx) {
    if(target == 0) {
        cout << ans << endl;
        return;
    }
    if(idx >= coins.size()) return;
    if(target - coins[idx] >= 0 && !vis[idx]) {
        vis[idx] = true;
        perWithoutRepSubseqApproach(coins, target - coins[idx], ans + to_string(coins[idx]), vis, 0);
        vis[idx] = false;
    }
    perWithoutRepSubseqApproach(coins, target, ans, vis, idx + 1);
}

void solve() {
    vector<int> coins = { 2, 3, 5, 7 };
    int target = 10;

    // ======================= Permutations =========================
    // Given an arr and a target, we have to identify the possible permutations
    // from the arr that sums up to given target.

    // perWithRep(coins, target, "");

    // vector<bool> vis(coins.size(), false);
    // perWithoutRep(coins, target, "", vis);


    // ======================= Combinations =========================
    // Given an arr and a target, we have to identify the possible combinations
    // from the arr that sums up to given target.

    // combWithRep(coins, target, "", 0);

    // combWithoutRep(coins, target, "", 0);


    // ==================== Subsequence Approach ====================
    // perWithRepSubseqApproach(coins, target, "", 0);
    // vector<bool> vis(coins.size(), false);
    // perWithoutRepSubseqApproach(coins, target, "", vis, 0);
    
    // combWithRepSubseqApproach(coins, target, "", 0);
    // combWithoutRepSubseqApproach(coins, target, "", 0);
}

int main() {
    solve();
    return 0;
}