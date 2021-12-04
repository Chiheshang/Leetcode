#include "Datastruct.h"
using namespace std;
class Solution {
public:
	TreeNode* connect(TreeNode* root) {
		TreeNode* cur = root;
		TreeNode* next = root;
		while (cur)
		{
			bool first = true;
			TreeNode* last = nullptr;
			while (cur) {
				if (first) {
					if (cur->left) {
						next = cur->left;
						first = false;
					}
					if (first && cur->right) {
						next = cur->right;
						first = false;
					}
				}
				if (cur->left) {
					if (last) {
						last->next = cur->left;
						last = cur->left;
					}
					else {
						last = cur->left;
					}
				}
				if (cur->right) {
					if (last) {
						last->next = cur->right;
						last = cur->right;
					}
					else
					{
						last = cur->right;
					}
				}
				cur = cur->next;
			}
			if (last)last->next = nullptr;
			cur = next;
			if (first)break;
		}
		return root;
	}
};
void trimLeftTrailingSpaces(string& input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
		}));
}

void trimRightTrailingSpaces(string& input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
		}).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	if (!input.size()) {
		return nullptr;
	}

	string item;
	stringstream ss;
	ss.str(input);

	getline(ss, item, ',');
	TreeNode* root = new TreeNode(stoi(item));
	queue<TreeNode*> nodeQueue;
	nodeQueue.push(root);

	while (true) {
		TreeNode* node = nodeQueue.front();
		nodeQueue.pop();

		if (!getline(ss, item, ',')) {
			break;
		}

		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int leftNumber = stoi(item);
			node->left = new TreeNode(leftNumber);
			nodeQueue.push(node->left);
		}

		if (!getline(ss, item, ',')) {
			break;
		}

		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int rightNumber = stoi(item);
			node->right = new TreeNode(rightNumber);
			nodeQueue.push(node->right);
		}
	}
	return root;
}

string treeNodeToString(TreeNode* root) {
	if (root == nullptr) {
		return "[]";
	}

	string output = "";
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode* node = q.front();
		q.pop();

		if (node == nullptr) {
			output += "null, ";
			continue;
		}

		output += to_string(node->val) + ", ";
		q.push(node->left);
		q.push(node->right);
	}
	return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		TreeNode* root = stringToTreeNode(line);

		TreeNode* ret = Solution().connect(root);

		string out = treeNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}