#include "Datastruct.h"

#include <fstream> 
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int i = 0, max = nums[0];
		while (i < nums.size() && i <= max)
		{
			max = std::max(max, i + nums[i]);
			if (i + 1 > max)break;
			i++;
			cout << max << endl;
		}
		cout << i << endl;
		if (i >= (nums.size() - 1))return true;
		else return false;
	}
};
int main() {
	vector<int> a = { 3,2,1,0,4 };
	Solution().canJump(a);
}