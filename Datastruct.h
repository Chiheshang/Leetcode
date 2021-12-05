#pragma once
#include<stddef.h>
#include<errno.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<vector>
#include<list>
#include<map>
#include<unordered_map>
#include <queue>
#include<set>
#include<unordered_set>
#include<stack>
#include <string>
#include <iostream>¡¡
#include <sstream> 
#include <algorithm>
#include<stdlib.h>
#include <functional>

#pragma once
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};
//class Node {
//public:
//	int val;
//	vector<Node*> neighbors;
//	Node() {
//		val = 0;
//		neighbors = vector<Node*>();
//	}
//	Node(int _val) {
//		val = _val;
//		neighbors = vector<Node*>();
//	}
//	Node(int _val, vector<Node*> _neighbors) {
//		val = _val;
//		neighbors = _neighbors;
//	}
//};