#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int kIncreasing(vector<int>& arr, int k) {
		int ans = 0;
		for (int i = k; i < arr.size(); i++) {
			if (arr[i] < arr[i - k]) {
				arr[i] = arr[i - k];
				ans++;
			}
		}
		return ans;
	}
};