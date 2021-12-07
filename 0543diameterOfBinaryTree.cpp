#include "Datastruct.h"
using namespace std;
class Solution {
public:
	int high(TreeNode* root) {
		if (!root)return 0;
		return std::max(high(root->left), high(root->right)) + 1;
	}
	int diameterOfBinaryTree(TreeNode* root) {
		if (!root)return 0;
		int ans = std::max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
		return std::max(ans, high(root->left) + high(root->right));
	}
};