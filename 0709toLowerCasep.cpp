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
	string toLowerCase(string s) {//λ����
		for (char& ch : s) {
			if (ch >= 65 && ch <= 90) {
				ch |= 32;//Сд��ĸasc2�ȴ�д��ĸ��32��
			}
		}
		return s;
	}
};