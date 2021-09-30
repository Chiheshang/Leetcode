#include"Datastruct.h"
using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode();
        ListNode* p = ans;
        bool carry = false;
        while (l1 && l2) {
            int cur = l1->val + l2->val + carry;
            l1 = l1->next;
            l2 = l2->next;
            carry = cur > 9 ? true : false;
            cur = cur % 10;
            p->next = new ListNode(cur);
            p = p->next;
        }
        while (l1) {
            int cur = l1->val + carry;
            l1 = l1->next;
            carry = cur > 9 ? true : false;
            cur = cur % 10;
            p->next = new ListNode(cur);
            p = p->next;
        }
        while (l2) {
            int cur = l2->val + carry;
            l2 = l2->next;
            carry = cur > 9 ? true : false;
            cur = cur % 10;
            p->next = new ListNode(cur);
            p = p->next;
        }
        if (carry) {
            p->next = new ListNode(1);
        }
        return ans->next;
    }
};