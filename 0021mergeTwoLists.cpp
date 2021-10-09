#include"Datastruct.h"
using namespace std;
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* ans = new ListNode();
		ListNode* p = ans;
		while (l1 || l2) {
			if (!l1) {
				p->next = new ListNode(l2->val);
				p = p->next;
				l2 = l2->next;
			}
			else if (!l2) {
				p->next = new ListNode(l1->val);
				p = p->next;
				l1 = l1->next;
			}
			else {
				int n1 = l1->val;
				int n2 = l2->val;
				if (n1 > n2) {
					p->next = new ListNode(n2);
					p = p->next;
					l2 = l2->next;
				}
				else {
					p->next = new ListNode(n1);
					p = p->next;
					l1 = l1->next;
				}
			}
		}
		return ans->next;
	}
};