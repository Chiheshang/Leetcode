/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.*/
//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };
//#include "Datastruct.h"
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        ListNode *fast = head, *low = head;
        if (!head || !head->next)
            return;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            low = low->next;
        }
        fast = low->next;
        low->next = nullptr;
        ListNode *last = nullptr, *cur = nullptr;
        while (fast->next)
        {
            cur = fast->next;
            fast->next = last;
            last = fast;
            fast = cur;
        }
        fast->next = last;
        low = head;
        head = new ListNode(0, head);
        ListNode *p = head;
        while (fast && low)
        {
            p->next = low;
            low = low->next;
            p = p->next;
            p->next = fast;
            p = p->next;
            fast = fast->next;
        }
        if (low)
        {
            p->next = low;
            p = p->next;
        }
        p->next = nullptr;
        return;
    }
};
// @lc code=end
