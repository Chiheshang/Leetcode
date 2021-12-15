#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
		int ans = 0;
		int left = 0, right = plants.size() - 1;
		int curA = capacityA;
		int curB = capacityB;
		while (left < right) {
			if (curA < plants[left]) {
				ans++;
				curA = capacityA;
				curA -= plants[left];
				left++;
			}
			else {
				curA -= plants[left];
				left++;
			}
			if (curB < plants[right]) {
				ans++;
				curB = capacityB;
				curB -= plants[right];
				right--;
			}
			else {
				curB -= plants[right];
				right--;
			}
		}
		if (left != right) {
			if (curA < curB) {
				if (curB < plants[right]) {
					ans++;
				}
			}
			else if (curA > curB) {
				if (curA < plants[left]) {
					ans++;
				}
			}
			else {
				if (curA < plants[left]) {
					ans++;
				}
			}
		}
		return ans;
	}
};
int main() {
	vector<int> a = { 2, 2, 3, 3 };
	Solution().minimumRefill(a, 3, 4);
}