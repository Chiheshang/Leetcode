/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

 // @lc code=start
 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode() : val(0), next(nullptr) {}
  *     ListNode(int x) : val(x), next(nullptr) {}
  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
  * };
  */
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
        if(!head)return head;
		ListNode* head1 = nullptr, * head2 = nullptr, * p1 = nullptr, * p2 = nullptr;
		while (head)
		{
			if (head->val < x) {
				if (!head1) {
					head1 = new ListNode(0, head);
					p1 = head1->next;
				}
				else {
					p1->next = head;
					p1 = p1->next;
				}
			}
			else {
				if (!head2) {
					head2 = new ListNode(0, head);
					p2 = head2->next;
				}
				else {
					p2->next = head;
					p2 = p2->next;
				}
			}
            head=head->next;
		}
		if (head1 == nullptr ^ head2 == nullptr) {
			head1 = head1 ? head1 : head2;
			p1 = p1 ? p1 : p2;
		}
		else {
			p1->next = head2->next;
			p1 = p2;
		}
		p1->next = nullptr;
		return head1->next;
	}
};
// @lc code=end

