#include"Datastruct.h"
using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		string str = to_string(x);
		string a = str;
		reverse(str.begin(), str.end());
		if (a == str)return true;
		else return false;
	}
};