#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int romanToInt(string s) {
		unordered_map<char, int> map;
		map.insert(make_pair('I', 1));
		map.insert(make_pair('V', 5));
		map.insert(make_pair('X', 10));
		map.insert(make_pair('L', 50));
		map.insert(make_pair('C', 100));
		map.insert(make_pair('D', 500));
		map.insert(make_pair('M', 1000));
		int ans = 0;
		for (int i = 0; i < s.size(); i++) {
			if (i < s.size() - 1 && map[s[i]] < map[s[i + 1]]) {
				ans -= map[s[i]];
				i++;
				ans += map[s[i]];
			}
			else {
				ans += map[s[i]];
			}
		}
		return ans;
	}
};
