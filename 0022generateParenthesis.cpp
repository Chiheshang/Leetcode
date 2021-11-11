#include"Datastruct.h"
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        stack<string> stack;
        vector<string> less = generateParenthesis(n - 1);
        for (string cur : generateParenthesis(n - 1)) {
            for (int i = 0; i < cur.size()-1; i++) {
                stack.push(cur.insert(i, "()"));
            }
            stack.push(cur+ "()");
        }
        vector<string> ans(&stack.top()+1-stack.size(), &stack.top() + 1);
        return ans;
    }
};