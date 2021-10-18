#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int findComplement(int num) {
		int ans = 0, temp = num;
		while (temp > 0) {
			temp >>= 1;
			ans = (ans << 1) + 1;
		}
		return ans ^ num;
	}
};