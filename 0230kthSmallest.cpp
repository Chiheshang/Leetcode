#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		int num_left = 0;
		if (root->left != nullptr) {
			num_left = getnum(root->left);
		}
		if (num_left > k - 1) {
			return kthSmallest(root->left, k);
		}
		else if (num_left < k - 1) {
			return kthSmallest(root->right, k - num_left - 1);
		}
		else {
			return root->val;
		}
	}
	int getnum(TreeNode* root) {
		if (root == nullptr)return 0;
		int left = 0, right = 0;
		if (root->left) {
			left = getnum(root->left);
		}
		if (root->right) {
			right = getnum(root->right);
		}
		return 1 + left + right;
	}
};
//void trimLeftTrailingSpaces(string& input) {
//	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
//		return !isspace(ch);
//		}));
//}
//
//void trimRightTrailingSpaces(string& input) {
//	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
//		return !isspace(ch);
//		}).base(), input.end());
//}
//
//TreeNode* stringToTreeNode(string input) {
//	trimLeftTrailingSpaces(input);
//	trimRightTrailingSpaces(input);
//	input = input.substr(1, input.length() - 2);
//	if (!input.size()) {
//		return nullptr;
//	}
//
//	string item;
//	stringstream ss;
//	ss.str(input);
//
//	getline(ss, item, ',');
//	TreeNode* root = new TreeNode(stoi(item));
//	queue<TreeNode*> nodeQueue;
//	nodeQueue.push(root);
//
//	while (true) {
//		TreeNode* node = nodeQueue.front();
//		nodeQueue.pop();
//
//		if (!getline(ss, item, ',')) {
//			break;
//		}
//
//		trimLeftTrailingSpaces(item);
//		if (item != "null") {
//			int leftNumber = stoi(item);
//			node->left = new TreeNode(leftNumber);
//			nodeQueue.push(node->left);
//		}
//
//		if (!getline(ss, item, ',')) {
//			break;
//		}
//
//		trimLeftTrailingSpaces(item);
//		if (item != "null") {
//			int rightNumber = stoi(item);
//			node->right = new TreeNode(rightNumber);
//			nodeQueue.push(node->right);
//		}
//	}
//	return root;
//}

//int stringToInteger(string input) {
//	return stoi(input);
//}
//
//int main() {
//	string line;
//	while (getline(cin, line)) {
//		TreeNode* root = stringToTreeNode(line);
//		getline(cin, line);
//		int k = stringToInteger(line);
//
//		int ret = Solution().kthSmallest(root, k);
//
//		string out = to_string(ret);
//		cout << out << endl;
//	}
//	return 0;
//}