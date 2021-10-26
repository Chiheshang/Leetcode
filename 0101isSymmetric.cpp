#include"Datastruct.h"
using namespace std;
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetricTree(root->left, root->right);
    }
    bool isSymmetricTree(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr)return true;
        if (root1 == nullptr || root2 == nullptr)return false;
        if (root1->val != root2->val)return false;
        return isSymmetricTree(root1->left, root2->right)
            && isSymmetricTree(root1->right, root2->left);
    }
};