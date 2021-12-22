/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &vec, int target)
    {
        if (vec.size() == 0)
            return {-1, -1};
        int left = 0, right = vec.size();
        int middle = (left + right) / 2;
        while (left < right)
        {
            middle = (left + right) / 2;
            if (vec[middle] > target)
            {
                right = middle;
            }
            else if (vec[middle] < target)
            {
                left = middle + 1;
            }
            else
                break;
        }
        if (vec[middle] != target)
            return {-1, -1};
        int a = middle, b = middle;
        while (a && vec[a - 1] == target)
            a--;
        while (b < vec.size() - 1 && vec[b + 1] == target)
            b++;
        return {a, b};
    }
};
// @lc code=end
