/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        if (!root)
            return ans;
        if (!root->left && !root->right)
        {
            ans.push_back(to_string(root->val));
            return ans;
        }
        vector<string> left = binaryTreePaths(root->left);
        vector<string> right = binaryTreePaths(root->right);
        for (string cur : left)
        {
            ans.push_back(to_string(root->val) + "->" + cur);
        }
        for (string cur : right)
        {
            ans.push_back(to_string(root->val) + "->" + cur);
        }
        return ans;
    }
};
// @lc code=end
