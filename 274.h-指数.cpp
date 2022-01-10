/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
// #include "Datastruct.h"
// using namespace std;
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end());
        int left = 0, right = citations.size();
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (citations[mid] >= mid && citations[mid - 1] < mid)
                return mid;
            else if (citations[mid] > mid)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return 0;
    }
};
// @lc code=end
