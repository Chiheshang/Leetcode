/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode *> stack;
        stack.push(root);
        while (root->left)
        {
            root = root->left;
            stack.push(root);
        }
        cout << stack.size() << endl;
        while (!stack.empty())
        {
            auto temp = stack.top();
            stack.pop();
            if (temp == nullptr)
                continue;
            ans.push_back(temp->val);
            temp = temp->right;
            if (temp == nullptr)
                continue;
            stack.push(temp);
            while (temp->left)
            {
                temp = temp->left;
                stack.push(temp);
            }
        }
        return ans;
    }
};
// @lc code=end
