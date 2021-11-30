#include "Datastruct.h"
using namespace std;
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		queue<TreeNode*> nextfloor;
		nextfloor.push(root);
		vector<vector<int>> ans;
		if (root == nullptr)return ans;
		int floor = 0;
		while (!nextfloor.empty())
		{
			floor++;
			queue<TreeNode*> next;
			deque<int> thisfloor;
			while (!nextfloor.empty()) {
				auto node = nextfloor.front();
				nextfloor.pop();
				if (floor % 2 == 1) {
					thisfloor.push_back(node->val);
				}
				else
				{
					thisfloor.push_front(node->val);
				}
				if (node->left)next.push(node->left);
				if (node->right)next.push(node->right);
			}
			ans.push_back(vector<int>(thisfloor.begin(),thisfloor.end()));
			nextfloor = next;
		}
		return ans;
	}
};