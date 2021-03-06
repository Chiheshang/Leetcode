/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
            return 0;
        int ans = 0;
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
        {
            ans += root->left->val;
        }
        cout << ans << endl;
        ans += sumOfLeftLeaves(root->left);
        ans += sumOfLeftLeaves(root->right);
        return ans;
    }
};
// @lc code=end
