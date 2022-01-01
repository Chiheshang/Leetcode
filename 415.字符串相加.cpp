/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ans = "";
        int i = 0, j = 0;
        bool carry = false;
        int n1 = 0, n2 = 0;
        while (i < num1.size() || j < num2.size())
        {
            n1 = i < num1.size() ? num1[i] - '0' : 0;
            n2 = j < num2.size() ? num2[j] - '0' : 0;
            ans = to_string((n1 + n2 + carry) % 10) + ans;
            carry = (n1 + n2 + carry) / 10;
            i++;
            j++;
        }
        if (carry)
            ans = "1" + ans;
        return ans;
    }
};
// @lc code=end
