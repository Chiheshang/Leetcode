#include"Datastruct.h"
using namespace std;
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ans;
		if (root == nullptr)return ans;
		vector<int> left = preorderTraversal(root->left);
		vector<int>right = preorderTraversal(root->right);
		ans.emplace_back(root->val);
		for_each(left.begin(), left.end(), [&ans](int cur) {ans.emplace_back(cur); });
		for_each(right.begin(), right.end(), [&ans](int cur) {ans.emplace_back(cur); });
		return ans;
	}
};