#include "Datastruct.h"
using namespace std;
class Solution {
public:
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		TreeNode* ans = new TreeNode();
		if (!root1 && !root2)return nullptr;
		if (!root1) {
			return root2;
		}
		else if (!root2) {
			return root1;
		}
		else {
			ans->val = root1->val + root2->val;
			ans->left = mergeTrees(root1->left, root2->left);
			ans->right = mergeTrees(root1->right, root2->right);
		}
		return ans;
	}
};