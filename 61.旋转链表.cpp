/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next)return head;
        stack<ListNode*> m_stack;
        ListNode* p=head;
        while(head){
            m_stack.push(head);
            head=head->next;
        }
        k%=m_stack.size();
        if(k==0)return p;
        ListNode* end=m_stack.top();
        for(int i=0;i<k-1;i++){
            m_stack.pop();
        }
        ListNode* new_head=m_stack.top();
        end->next=p;
        m_stack.pop();
        m_stack.top()->next=nullptr;
        return new_head;
    }
};
// @lc code=end

