#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int k)
    {
        val = k;
    }
};

// Question 1. =========================================
TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
{
    if (t1 == nullptr || t2 == nullptr)
        return t1 == nullptr ? t2 : t1;

    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);

    return t1;
}

// Question 2. =========================================
int ans = 0;
void solve(TreeNode *root, bool isLeft)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr && isLeft)
    {
        ans += root->val;
        return;
    }

    solve(root->left, true);
    solve(root->right, false);
}
int sumOfLeftLeaves(TreeNode *root)
{
    solve(root, false);
    return ans;
}

// Question 3. =========================================
int sum = 0;
TreeNode *convertBST(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;

    convertBST(root->right);
    sum += root->val;
    root->val = sum;
    convertBST(root->left);

    return root;
}

// Question 4. =========================================
int max_ = 0;
int solve(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int left = solve(root->left);
    int right = solve(root->right);

    if (root->left != nullptr && root->left->val == root->val)
        left += 1;
    else
        left = 0;
    if (root->right != nullptr && root->right->val == root->val)
        right += 1;
    else
        right = 0;

    max_ = max(max_, left + right);
    return max(left, right);
}
int longestUnivaluePath(TreeNode *root)
{
    solve(root);
    return max_;
}

// Question 5. =========================================
int mindiff = (int)1e8;
int getMinimumDifference(TreeNode *root)
{
    solve2(root);
    return mindiff;
}
TreeNode *prevNode = nullptr;
void solve2(TreeNode *node)
{
    if (node == nullptr)
        return;

    solve2(node->left);
    if (prevNode != nullptr)
        mindiff = min(mindiff, abs(node->val - prevNode->val));
    prevNode = node;
    solve2(node->right);
}

// Question 6. =========================================
int solve3(vector<int> freq, int i, int j, int level)
{
    if (i > j)
        return 0;

    int optimalCost = (int)1e8;
    for (int k = i; k <= j; k++)
    {
        int leftOptimalCost = solve3(freq, i, k - 1, level + 1);
        int rightOptimalCost = solve3(freq, k + 1, j, level + 1);
        int cost = freq[k] * level + leftOptimalCost + rightOptimalCost;
        optimalCost = min(optimalCost, cost);
    }

    return optimalCost;
}
void optimalCostBST()
{
    vector<int> freq = {25, 10, 20};
    int n = freq.size();
    cout << solve3(freq, 0, n - 1, 1);
}

int main()
{
    return 0;
}