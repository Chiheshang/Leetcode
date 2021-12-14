/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
 //#include "Datastruct.h"
 //using namespace std;
class Solution {
public:
    ListNode* mergeKLists1(vector<ListNode*>& lists) {//无效做法
        vector<int> array;
        for(auto cur:lists){
            while(cur){
                array.push_back(cur->val);
                cur=cur->next;
            }
        }
        sort(array.begin(),array.end());
        ListNode* head=nullptr,*p=nullptr;
        for(int i=0;i<array.size();i++){
            if(!head){
                head=new ListNode(array[i]);
                p=head;
            }
            else{
                p->next=new ListNode(array[i]);
                p=p->next;
            }
        }
        return head;
    }
    struct node{
        int val;
        ListNode* ptr;
        bool operator < (const node & oth) {
            return val>oth.val;
        }
        node(int val,ListNode* ptr):val(val),ptr(ptr){}
    };
    priority_queue<node*> q;
    ListNode* mergeKLists(vector<ListNode*>& lists) {//priority_queue
        for(auto cur:lists){
           if(cur){
               node* temp=new node(cur->val,cur);
               q.push(temp);
           }
        }
        ListNode head, *tail = &head;
        while(!q.empty()){
            auto cur=q.top();
            q.pop();
            tail->next = cur->ptr; 
            tail = tail->next;
            if(cur->ptr->next){
                node* temp=new node(cur->ptr->next->val,cur->ptr->next);
                q.push(temp);
            }
        }
        return head.next;
    }
  

};
// @lc code=end