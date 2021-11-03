#include"Datastruct.h"
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for (int cur : nums) {
            ans = ans ^ cur;
        }
        return ans;
    }
};