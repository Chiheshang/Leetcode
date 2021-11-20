#include"Datastruct.h"
using namespace std;
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> num;
        for (int cur : nums) {
            num[cur]++;
        }
        int ans = 0;
        int num_last = num.begin()->first;
        int count_last = num.begin()->second;
        auto it = num.begin();
        for (it++; it != num.end();it++) {
            if (it->first == num_last + 1) {
                ans = std::max(ans, count_last + it->second);
            }
            num_last = it->first;
            count_last = it->second;
        }
        return ans;
    }
};