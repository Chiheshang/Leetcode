#include"Datastruct.h"
using namespace std;
class Solution {
private:
	vector<int> arr, origin;
public:
	Solution(vector<int>& nums) {
		arr = vector<int>(nums);
		origin = vector<int>(nums);
	}

	vector<int> reset() {
		return origin;
	}

	vector<int> shuffle() {
		next_permutation(arr.begin(), arr.end());
		return arr;
	}
};
