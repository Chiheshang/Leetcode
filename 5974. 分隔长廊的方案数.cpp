#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int numberOfWays(string corridor) {
		int numS = 0;
		for (char cur : corridor) {
			if (cur == 'S')numS++;
		}
		if (numS % 2 != 0)return 0;
		long long ans = 1;
		int temp = 0;
		for (int i = 0; i < corridor.size(); i++) {
			if (temp == 2) {
				temp = 0;
				int num = 0;
				while (i + num < corridor.size() && corridor[i + num] == 'P') {
					num++;
				}
				if (i + num == corridor.size())break;
				i += num;
				ans *= num + 1;
				ans %= 1000000007;
				if (corridor[i] == 'S')temp++;
			}
			else {
				if (corridor[i] == 'S')temp++;
			}
		}
		return ans;
	}
};
int main() {
	Solution().numberOfWays("SPPSSSSPPS");
}