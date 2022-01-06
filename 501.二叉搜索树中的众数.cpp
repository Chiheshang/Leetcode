/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    map<int, int> count;
    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;
        count[root->val]++;
        if (root->left)
            dfs(root->left);
        if (root->right)
            dfs(root->right);
    }
    vector<int> findMode(TreeNode *root)
    {
        count.clear();
        vector<int> ans;
        dfs(root);
        int max = 0;
        for (auto itor = count.begin(); itor != count.end(); itor++)
        {
            max = std::max(max, itor->second);
        }
        for (auto itor = count.begin(); itor != count.end(); itor++)
        {
            if (itor->second == max)
            {
                ans.push_back(itor->first);
            }
        }
        return ans;
    }
};
// @lc code=end
