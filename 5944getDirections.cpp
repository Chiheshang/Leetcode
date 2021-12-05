#include "Datastruct.h"
using namespace std;
class Solution {
public:
	string getDirections(TreeNode* root, int startValue, int destValue) {//ºÜÆ¯ÁÁµÄÐ´·¨
		string a, b;
		function<bool(TreeNode*, int, string&)> f = [&](TreeNode* root, int x, string& road) {
			if (root == nullptr) return false;
			if (root->val == x) return true;
			if (f(root->left, x, road)) {
				road.push_back('L');
				return true;
			}
			if (f(root->right, x, road)) {
				road.push_back('R');
				return true;
			}
			return false;
		};
		f(root, startValue, a);
		f(root, destValue, b);
		while (a.size() && b.size() && a.back() == b.back()) a.pop_back(), b.pop_back();
		string ans(a.size(), 'U');
		reverse(begin(b), end(b));
		return ans + b;
	}
	unordered_map<TreeNode*, TreeNode*> father;
	unordered_map<int, bool> visited;
	void creatFather(TreeNode*& root) {
		if (!root)return;
		if (root->left) {
			father[root->left] = root;
			creatFather(root->left);
		}
		if (root->right) {
			father[root->right] = root;
			creatFather(root->right);
		}
	}
	TreeNode* findNode(TreeNode*& root, int val) {
		if (root == nullptr)return nullptr;
		if (root->val == val)return root;
		TreeNode* le = findNode(root->left, val);
		if (le)return le;
		TreeNode* ri = findNode(root->right, val);
		if (ri)return ri;
		return nullptr;
	}
	string getDirections(TreeNode* root, int startValue, int destValue) {
		father.clear();
		father[root] = nullptr;
		creatFather(root);
		TreeNode* start = findNode(root, startValue);
		TreeNode* end = findNode(root, destValue);
		TreeNode* p = start;
		visited.clear();
		while (p) {
			visited[p->val] = true;
			p = father[p];
		}
		p = end;
		while (p)
		{
			if (visited.find(p->val) != visited.end()) break;
			p = father[p];
		}
		string ans = "";
		while (start != p) {
			ans.insert(ans.end(), 'U');
			start = father[start];
		}
		string right = "";
		while (end != p)
		{
			TreeNode* fa = father[end];
			if (fa->left == end) {
				right.insert(right.begin(), 'L');
			}
			else if (fa->right == end) {
				right.insert(right.begin(), 'R');
			}
			end = fa;
		}
		ans.append(right);
		return ans;
	}
};