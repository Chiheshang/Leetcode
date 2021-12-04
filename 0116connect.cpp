#include "Datastruct.h"
using namespace std;
class Solution {
public:
	TreeNode* connect(TreeNode* root) {
		if (!root || !root->left)return root;
		root->left->next = root->right;
		if (root->next)
			root->right->next = root->next->left;
		connect(root->left);
		connect(root->right);
		return root;
	}
	TreeNode* connect(TreeNode* root) {
		//non-cursive
		if (!root || !root->left)return root;
		TreeNode* cur = root;
		TreeNode* next = root;
		while (cur)
		{
			next = cur->left;
			while (cur && cur->left) {
				cur->left->next = cur->right;
				if (cur->next)
				{
					cur->right->next = cur->next->left;
				}
				cur = cur->next;
			}
			cur = next;
		}
		return root;
	}
};