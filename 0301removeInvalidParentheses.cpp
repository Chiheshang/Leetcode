#include"Datastruct.h"
using namespace std;
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        set<string> m_set;
        bool thislevel = true;
        for (int i = 0; i < s.size(); i++) {
            string removeone = s.erase(i, 1);
            m_set.insert(removeone);
            if (!whetherLegal(removeone)) {
                thislevel = false;
            }
        }
        if (thislevel) {
            
        }
    }
    bool whetherLegal(string s) {
        stack<char> m_stack;
        for (char cur : s) {
            if (cur == '(') {
                m_stack.push(cur);
            }
            else if (cur == ')') {
                if (m_stack.top() != '(') {
                    return false;
                }
                else {
                    m_stack.pop();
                }
            }
        }
        if (m_stack.empty())return true;
        else return false;
    }
};