/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution
{
public:
    int addDigits(int num)
    {
        int temp = 0;
        while (num > 9)
        {
            temp=0;
            while (num > 0)
            {
                temp += num % 10;
                num /= 10;
            }
            num=temp;
        }
        return num;
    }
};
// @lc code=end
