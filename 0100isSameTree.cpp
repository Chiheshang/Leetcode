#include"Datastruct.h"
using namespace std;
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr)return true;
		if (p == nullptr || q == nullptr)return false;
		if (isSameTree(p->right, q->right) && isSameTree(p->left, q->left) && p->val == q->val) {
			return true;
		}
		else return false;
	}
};