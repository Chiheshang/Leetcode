/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

// @lc code=start
class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (denominator == 0)
            return "";
        if (numerator == 0)
            return "0";
        unordered_map<long, int> appear;
        string ans = "";
        bool pos = !(numerator > 0) ^ (denominator > 0);
        if (!pos)
            ans += "-";
        numerator = abs(numerator);
        denominator = abs(denominator);
        cout << numerator / denominator << endl;
        long p = (long)numerator / (long)denominator;
        p = abs(p);
        ans += to_string(p);
        long rem = (long)numerator % denominator;
        if (rem == 0)
            return ans;
        ans += ".";
        while (rem)
        {
            appear[rem] = ans.size();
            rem *= 10;
            ans += to_string(rem / (long)denominator);
            rem %= denominator;
            if (appear.find(rem) != appear.end())
            {
                ans.insert(appear[rem], "(");
                ans += ")";
                break;
            }
        }
        return ans;
    }
};

// @lc code=end
