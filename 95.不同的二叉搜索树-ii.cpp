/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode *> generateTrees(int n)
    {
        vector<TreeNode *> ans = help(1, n);
        return ans;
    }
    vector<TreeNode *> help(int begin, int end)
    {
        vector<TreeNode *> ans;
        if (begin > end)
        {
            ans.push_back(nullptr);
            return ans;
        }
        for (int i = begin; i <= end; i++)
        {
            vector<TreeNode *> left = help(begin, i - 1);
            vector<TreeNode *> right = help(i + 1, end);
            for (int j = 0; j < left.size(); j++)
            {
                for (int k = 0; k < right.size(); k++)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
