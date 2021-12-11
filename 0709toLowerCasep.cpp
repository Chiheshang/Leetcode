#include"Datastruct.h"
using namespace std;
class Solution {
public:
	string toLowerCase(string s) {
		string ans;
		for (char cur : s) {
			ans = ans + (char)tolower(cur);
		}
		return ans;
	}
	string toLowerCase(string s) {//位运算
		for (char& ch : s) {
			if (ch >= 65 && ch <= 90) {
				ch |= 32;//小写字母asc2比大写字母大32；
			}
		}
		return s;
	}
};