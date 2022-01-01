/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;se
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode *> set;
        while (head!=nullptr)
        {
            if(set.find(head)!=set.end())return head;
            else set.insert(head);
            head=head->next;
        }
        return nullptr;
    }
};
// @lc code=end

