/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include<stack>
// @lc code=start
class MyQueue {
    stack<int> m_stack1;
    stack<int> m_stack2;
    stack<int> temp;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        m_stack1.push(x);
    }
    
    int pop() {
        while (!m_stack1.empty())
        {
            m_stack2.push(m_stack1.top());
            m_stack1.pop();
        }
        int ans=m_stack2.top();
        m_stack2.pop();
        while (!m_stack2.empty())
        {
            m_stack1.push(m_stack2.top());
            m_stack2.pop();
        }
        return ans;
    }
    
    int peek() {
        temp=m_stack1;
        while (!m_stack1.empty())
        {
            m_stack2.push(m_stack1.top());
            m_stack1.pop();
        }
        int ans=m_stack2.top();
        m_stack2=m_stack1;
        m_stack1=temp;
        return ans;
    }
    
    bool empty() {
        return m_stack1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

