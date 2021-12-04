#include "Datastruct.h"
using namespace std;
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		if (!root)return vector<vector<int>>();
		deque<vector<int>> ans;
		vector<TreeNode*>level;
		level.push_back(root);
		while (!level.empty())
		{
			vector<TreeNode*> next;
			vector<int> thislevel;
			for (auto cur : level) {
				thislevel.push_back(cur->val);
				if (cur->left)next.push_back(cur->left);
				if (cur->right)next.push_back(cur->right);
			}
			ans.push_front(thislevel);
			level = next;
		}
		return vector<vector<int>>(ans.begin(),ans.end());
	}
};