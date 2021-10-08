#include"Datastruct.h"
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		stack<char> m_stack;
		for (char cur : s) {
			switch (cur)
			{
			case'(': {
				m_stack.push(cur);
				break;
			}
			case')': {
				if(m_stack.pop()!='(')
			}
			default:
				break;
			}
		}
	}
};