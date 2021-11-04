#include"Datastruct.h"
using namespace std;
class MinStack {
private:
    stack<int> m_stack;
    stack<int>min;
public:
    MinStack() {
    }

    void push(int val) {
        m_stack.push(val);
        if (min.size() == 0|| min.top() >= val)min.push(val);
    }

    void pop() {
        if (m_stack.top() == min.top())min.pop();
        m_stack.pop();
        
    }

    int top() {
        return m_stack.top();
    }

    int getMin() {
        return min.top();
    }
};