#include"Datastruct.h"
using namespace std;
//class MapSum {//±©Á¦
//private:
//	map<string, int> m_map;
//public:
//	MapSum() {
//		m_map.clear();
//	}
//
//	void insert(string key, int val) {
//		m_map[key] = val;
//	}
//
//	int sum(string prefix) {
//		int ans = 0;
//		for (auto it = m_map.begin(); it != m_map.end(); it++) {
//			if (it->first.find(prefix) == 0)ans += it->second;
//		}
//		return ans;
//	}
//};
//×ÖµäÊ÷
class Trie
{
private:
	vector<Trie*> children;
	bool isend;
	int val;
public:
	Trie() :children(26), isend(false) {};
	void insert(string word,int value) {
		Trie* node = this;
		for (char cur : word) {
			if (node->children[cur - 'a'] == nullptr) {
				node->children[cur - 'a'] = new Trie;
			}
			node = node->children[cur - 'a'];
		}
		node->isend = true;
		node->val = value;
	}
	bool search(string word) {
		Trie* node = this;
		for (char cur : word) {
			if (node->children[cur - 'a'] == nullptr) {
				return false;
			}
			else {
				node = node->children[cur - 'a'];
			}
		}
		return node->isend;
	}
	bool startsWith(string prefix) {
		Trie* node = this;
		for (char cur : prefix) {
			if (node->children[cur - 'a'] == nullptr) {
				return false;
			}
			else {
				node = node->children[cur - 'a'];
			}
		}
		return true;
	}
	int sum(string word) {
		Trie* node = this;
		int sum = 0;
		for (char cur : word) {
			if (node->children[cur - 'a'] == nullptr)return 0;
			node = node->children[cur - 'a'];
		}
		return sumtree(node);
	}
	int sumtree(Trie* node) {
		if (node == nullptr)return 0;
		int sum = 0;
		if (node->isend)sum += node->val;
		for (Trie* cur : node->children) {
			sum += sumtree(cur);
		}
		return sum;
	}
};
class MapSum {
private:
	Trie* tree;
public:
	MapSum() {
		tree = new Trie;
	}

	void insert(string key, int val) {
		tree->insert(key,val);
	}

	int sum(string prefix) {
		return tree->sum(prefix);
	}
};
//int main() {
//	MapSum m_map;
//	m_map.insert("ab", 3);
//	m_map.insert("abc", 2);
//	int a = m_map.sum("ab");
//	int b = 0;
//}