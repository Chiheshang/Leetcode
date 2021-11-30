#include "Datastruct.h"
using namespace std;
class Solution {
public:
	unordered_map<Node*, Node*> visited;
	Node* cloneGraph(Node* node) {//dfs
		if (node == nullptr)return node;
		if (visited.find(node) != visited.end()) {
			return visited[node];
		}
		Node* temp = new Node(node->val);
		visited[node] = temp;
		for (auto neigh : node->neighbors) {
			temp->neighbors.emplace_back(cloneGraph(neigh));
		}

		return temp;
	}
	Node* cloneGraph(Node* node) {//bfs ÄÑÐ´£¬¼ÓÇ¿¶ÍÁ¶
		if (node == nullptr)return node;
		queue<Node*> m_queue;
		m_queue.push(node);
		unordered_map<Node*, Node*> visited;
		visited[node] = new Node(node->val);
		while (!m_queue.empty())
		{
			Node* temp = m_queue.front();
			m_queue.pop();
			for (auto neigh : temp->neighbors) {
				if (visited.find(neigh) == visited.end()) {
					visited[neigh] = new Node(neigh->val);
					m_queue.push(neigh);
				}
				visited[temp]->neighbors.push_back(neigh);
			}
		}
		return visited[node];
	}
};