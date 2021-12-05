#include "Datastruct.h"
using namespace std;
class Solution {
public:
	ListNode* deleteMiddle(ListNode* head) {
		if (head == nullptr)return head;
		ListNode* fast = head;
		ListNode* low = head;
		while (fast->next!=nullptr&&fast->next->next!=nullptr)
		{
			fast = fast->next->next;
			low = low->next;
		}
		if (fast->next==nullptr)
		{
			if (low->next == nullptr)head = nullptr;
			else {
				low->val = low->next->val;
				low->next = low->next->next;
			}
		}
		else
		{
			if (low->next->next == nullptr)low->next = nullptr;
			else {
				low = low->next;
				low->val = low->next->val;
				low->next = low->next->next;
			}
		}
		return head;
	}
};