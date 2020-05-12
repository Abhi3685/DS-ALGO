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
int pathSum(TreeNode *root, int sum)
{
    if (root == nullptr)
        return 0;

    return helper(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
}

int helper(TreeNode *node, int sum)
{
    if (node == nullptr)
        return 0;

    int count = 0;
    if (node->val == sum)
        ++count;
    count += helper(node->left, sum - node->val);
    count += helper(node->right, sum - node->val);
    return count;
}

// Question 2. =========================================
TreeNode *removeLeafNodes(TreeNode *root, int target)
{
    if (root == nullptr)
        return nullptr;

    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);

    if (root->left == nullptr && root->right == nullptr && root->val == target)
        return nullptr;
    return root;
}

// Question 3. =========================================
TreeNode *constructMaximumBinaryTree(vector<int> &nums)
{
    return construct(nums, 0, nums.size() - 1);
}
TreeNode *construct(vector<int> &nums, int l, int r)
{
    if (l > r)
        return nullptr;
    int max_i = max(nums, l, r);
    TreeNode *root = new TreeNode(nums[max_i]);
    root->left = construct(nums, l, max_i - 1);
    root->right = construct(nums, max_i + 1, r);
    return root;
}
int max(vector<int> &nums, int l, int r)
{
    int max_i = l;
    for (int i = l; i <= r; i++)
    {
        if (nums[max_i] < nums[i])
            max_i = i;
    }
    return max_i;
}

// Question 4. =========================================
int max_ = 0;
int leafToLeafMaxSum(TreeNode *node)
{
    if (node == nullptr)
        return 0;

    int leftToLeaf = leafToLeafMaxSum(node->left);
    int rightToLeaf = leafToLeafMaxSum(node->right);
    if (node->left != nullptr && node->right != nullptr)
    {
        max_ = max(max_, leftToLeaf + rightToLeaf + node->val);
        return max(leftToLeaf, rightToLeaf) + node->val;
    }

    return (node->left == nullptr ? rightToLeaf : leftToLeaf) + node->val;
}

// Question 5. =========================================
int max2_ = 0;
int nodeToNodeMaximum(TreeNode *node)
{
    if (node == nullptr)
        return 0;

    int leftToNode = nodeToNodeMaximum(node->left);
    int rightToNode = nodeToNodeMaximum(node->right);

    if (node->left != nullptr && node->right != nullptr)
    {
        max2_ = max(max2_, leftToNode + rightToNode + node->val);
    }
    max2_ = max(max2_, max(leftToNode, rightToNode) + node->val);
    return max(max(leftToNode, rightToNode), node->val);
}

int main()
{
    return 0;
}