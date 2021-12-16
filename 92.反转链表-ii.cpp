/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        head= new ListNode(0,head);
        ListNode *p = head, *le_pre = nullptr, *le = nullptr, *ri = nullptr,*ri_after=nullptr;
        for(int i=0;i<=right;i++,p=p->next){
            if(i==left-1)le_pre=p;
            if(i==left)le=p;
            if(i==right)ri=p;
        }
        if(ri->next)ri_after=ri->next;
        ListNode * pre=nullptr,*cur=nullptr;
        ri->next=nullptr;
        ri=le;
        while (le)
        {
            cur=le->next;
            le->next=pre;
            pre=le;
            le=cur;
        }
        le_pre->next=pre;
        ri->next=ri_after;
        return head->next;
    }
};
// @lc code=end
