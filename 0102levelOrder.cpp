#include "Datastruct.h"
using namespace std;
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> nextfloor;
		nextfloor.push(root);
		vector<vector<int>> ans;
		if (root == nullptr)return ans;
		while (!nextfloor.empty())
		{
			queue<TreeNode*> next;
			vector<int> thisfloor;
			while (!nextfloor.empty()) {
				auto node = nextfloor.front();
				nextfloor.pop();
				thisfloor.push_back(node->val);
				if (node->left != nullptr)next.push(node->left);
				if (node->right != nullptr)next.push(node->right);
			}
			ans.push_back(thisfloor);
			nextfloor = next;
		}
		return ans;
	}
};