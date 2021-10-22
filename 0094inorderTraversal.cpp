#include"Datastruct.h"
using namespace std;
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> left;
		if (root == nullptr)return left;
		vector<int> right;
		if (root->left != nullptr) {
			left = inorderTraversal(root->left);
		}if (root->right != nullptr) {
			right = inorderTraversal(root->right);
		}
		left.emplace_back(root->val);
		left.insert(left.end(), right.begin(), right.end());
		return left;
	}
};