#include"Datastruct.h"
using namespace std;
class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		if (headA == nullptr || headB == nullptr) return nullptr;
		ListNode* pa = headA, * pb = headB;
		while (pa != pb) {
			pa = pa == NULL ? headB : pa->next;
			pb = pb == NULL ? headA : pb->next;
		}
		return pa;
	}
};