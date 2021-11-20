#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int hammingWeight(uint32_t n) {
		uint32_t tag = 1;
		int ans = 0;
		for (int i = 0; i < 32; i++) {
			if ((n & tag) != 0)ans++;
			tag = tag << 1;
		}
		return ans;
	}
};
int main() {
	Solution().hammingWeight(11);
}