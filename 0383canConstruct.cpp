#include "Datastruct.h"
using namespace std;
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		vector<int> ran(26, 0);
		vector<int> mag(26, 0);
		for_each(ransomNote.begin(), ransomNote.end(), [&ran](char cur) {ran[cur - 'a']++; });
		for_each(magazine.begin(), magazine.end(), [&mag](char cur) {mag[cur - 'a']++; });
		for (int i = 0; i < 26; i++) {
			if (ran[i] > mag[i])return false;
		}
		return true;
	}
};