/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution1
{
    vector<int> vec;

public:
    void addvec(TreeNode *root)
    {
        if (root == nullptr)
            return;
        vec.push_back(root->val);
        addvec(root->left);
        addvec(root->right);
    }
    int getMinimumDifference(TreeNode *root)
    {
        vec.clear();
        vec.reserve(10000);
        addvec(root);
        sort(vec.begin(), vec.end());
        int min = __INT32_MAX__;
        for (int i = 1; i < vec.size(); i++)
        {
            min = std::min(min, vec[i] - vec[i - 1]);
        }
        return min;
    }
};
class Solution
{
private:
    int diff = __INT16_MAX__;
    TreeNode *pre;

public:
    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;
        dfs(root->left);
        if (pre)
            diff = std::min(diff, abs(pre->val - root->val));
        pre = root;
        dfs(root->right);
    }
    int getMinimumDifference(TreeNode *root)
    {
        dfs(root);
        return diff;
    }
};
// @lc code=end
