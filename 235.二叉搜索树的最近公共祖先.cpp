/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return root;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        TreeNode* s=root;
        while (s!=p)
        {
            q1.push(s);
            if(p->val<s->val)s=s->left;
            else s=s->right;
        }
        q1.push(s);
        s=root;
        while (s!=q)
        {
            q2.push(s);
            if(q->val<s->val)s=s->left;
            else s=s->right;
        }
        q2.push(s);
        TreeNode* ans;
        while(q1.front()==q2.front()){
            ans=q1.front();
            q1.pop();
            q2.pop();
        }
        return ans;
    }
};
// @lc code=end

