#include"Datastruct.h"
using namespace std;
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* p = head;
		while (p != nullptr) {
			if (p->next == nullptr) {
				break;
			}
			while (p->next != nullptr && p->val == p->next->val) {
				p->next = p->next->next;
			}
			p = p->next;
		}
		return head;
	}
};