#include "Datastruct.h"
using namespace std;
class Solution {
public:
	unordered_map<TreeNode*, TreeNode*> visited;
	TreeNode* cloneGraph(TreeNode* node) {//dfs
		if (node == nullptr)return node;
		if (visited.find(node) != visited.end()) {
			return visited[node];
		}
		TreeNode* temp = new TreeNode(node->val);
		visited[node] = temp;
		for (auto neigh : node->neighbors) {
			temp->neighbors.emplace_back(cloneGraph(neigh));
		}

		return temp;
	}
	TreeNode* cloneGraph(TreeNode* node) {//bfs ÄÑÐ´£¬¼ÓÇ¿¶ÍÁ¶
		if (node == nullptr)return node;
		queue<TreeNode*> m_queue;
		m_queue.push(node);
		unordered_map<TreeNode*, TreeNode*> visited;
		visited[node] = new TreeNode(node->val);
		while (!m_queue.empty())
		{
			TreeNode* temp = m_queue.front();
			m_queue.pop();
			for (auto neigh : temp->neighbors) {
				if (visited.find(neigh) == visited.end()) {
					visited[neigh] = new TreeNode(neigh->val);
					m_queue.push(neigh);
				}
				visited[temp]->neighbors.push_back(neigh);
			}
		}
		return visited[node];
	}
};