#include"Datastruct.h"
using namespace std;
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr)return head;
		stack <ListNode*> m_stack;
		while (head != nullptr) {
			m_stack.push(head);
			head = head->next;
		}
		ListNode* p = m_stack.top();
		head = p;
		m_stack.pop();
		while (!m_stack.empty())
		{
			p->next = m_stack.top();
			p = p->next;
			m_stack.pop();
		}
		p->next = nullptr;
		return head;
	}
};