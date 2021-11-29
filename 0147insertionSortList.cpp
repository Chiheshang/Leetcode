#include"Datastruct.h"
using namespace std;
class Solution {
public:
	ListNode* m_sort(ListNode* head, int val) {
		if (head == nullptr)
		{
			return new ListNode(val);
		}
		ListNode* p = head;
		while (p->next != nullptr)
		{
			if (p->next->val >= val) {
				ListNode* temp = new ListNode(val, p->next);
				p->next = temp;
				return head;
			}
			p = p->next;
		}
		p->next = new ListNode(val);
		return head;
	}
	ListNode* insertionSortList(ListNode* head) {
		ListNode* next = head->next;
		head->next = new ListNode(head->val);
		while (next != nullptr) {
			head = m_sort(head, next->val);
			next = next->next;
		}
		return head->next;
	}
};