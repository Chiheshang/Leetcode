/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        map<Node *, Node *> index;
        Node *newhead = new Node(head->val);
        Node *p = head;
        Node *q = newhead;
        index[p] = q;
        while (p->next)
        {
            q->next = new Node(p->next->val);
            index[p->next] = q->next;
            p = p->next;
            q = q->next;
        }
        p = head;
        q = newhead;
        while (q != nullptr)
        {
            q->random = index[p->random];
            p = p->next;
            q = q->next;
        }
        return newhead;
    }
};
// @lc code=end
