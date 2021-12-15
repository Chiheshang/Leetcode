#include"Datastruct.h"
using namespace std;
class Solution {
public:
	void quicksort1(vector<int>& nums, int left, int right) {
		if (left >= right)return;
		int ran = rand() % (right - left + 1) + left;
		swap(nums[ran], nums[left]);
		int judge = nums[left];
		int i = left, j = right;
		while (i < j) {
			while (j > i && nums[j] > judge)j--;
			nums[i] = nums[j];
			while (j > i && nums[i] <= judge)i++;
			nums[j] = nums[i];
		}
		nums[i] = judge;
		quicksort1(nums, left, i - 1);
		quicksort1(nums, i + 1, right);
	}
	int partsort(vector<int>& nums, int left, int right)
	{
		int random = rand() % (right - left + 1) + left;
		swap(nums[left], nums[random]);
		int prev = left + 1;
		int cur = left;
		int key = left;
		while (prev <= right)
		{
			if (nums[prev] < nums[key] && prev != cur)
				swap(nums[prev], nums[++cur]);
			prev++;
		}
		swap(nums[cur], nums[key]);
		return cur;
	}
	void quicksort2(vector<int>& nums, int left, int right) {
		if (left >= right)
			return;
		int key = partsort(nums, left, right);
		quicksort2(nums, left, key - 1);
		quicksort2(nums, key + 1, right);
	}
	vector<int> sortArray(vector<int>& nums) {
		quicksort1(nums, 0, nums.size() - 1);
		quicksort2(nums, 0, nums.size() - 1);
		return nums;
	}
};
int main() {
	vector<int> a = { 5,1,1,2,0,0 };
	a = Solution().sortArray(a);
}