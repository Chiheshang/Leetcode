#include"Datastruct.h"
using namespace std;
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> raw;
		if (digits.size() == 0)return raw;
		raw.push_back("");
		vector<string> really;
		vector<vector<char>> key = {
			{} ,{}, {'a','b','c'},{'d','e','f'},
			{'g','h','i'},{'j','k','l'},{'m','n','o'},
			{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}
		};
		for (char cur : digits) {
			for (string cur_raw : raw) {
				for (char cur_num : key[cur - '0']) {
					really.push_back(cur_raw + cur_num);
				}
			}
			raw = really;
			really.clear();
		}
		return raw;
	}
};