#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int pairSum(ListNode* head) {
		vector<int> vec;
		vec.reserve(10000);
		ListNode* p = head;
		while (p)
		{
			vec.push_back(p->val);
			p = p->next;
		}
		int max = 0;
		int len = vec.size();
		for (int i = 0; i < (len + 1) / 2; i++) {
			max = std::max(max, vec[i] + vec[len - 1 - i]);
		}
		return max;
	}
};