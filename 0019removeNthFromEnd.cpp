#include"Datastruct.h"
using namespace std;
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		stack<ListNode*> m_stack;
		ListNode* p = head;
		while (p != nullptr) {
			m_stack.push(p);
			p = p->next;
		}
		for (; n > 1; n--) {
			m_stack.pop();
		}
		p = m_stack.top();
		if (head == p) {
			head = head->next;
			return head;
		}
		m_stack.pop();
		m_stack.top()->next = m_stack.top()->next->next;
		return head;
	}
};