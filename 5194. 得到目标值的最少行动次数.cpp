#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int minMoves(int target, int maxDoubles) {
		int ans = 0;
		int cur = 0;
		while (target > 1 && cur < maxDoubles)
		{
			if (target % 2 == 1) {
				target--;
				ans++;
			}
			else {
				target /= 2;
				ans++;
				cur++;
			}
		}
		if (target > 1)ans += target - 1;
		return ans;
	}

};