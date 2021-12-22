/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
//#include "Datastruct.h"
//using namespace std;
class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string temp = countAndSay(n - 1);
        string ans="";
        int num = 1;
        for (int i = 1; i < temp.size(); i++)
        {
            if (i < temp.size() && temp[i] == temp[i - 1])
            {
                num++;
                continue;
            }
            ans = ans + to_string(num);
            ans = ans + temp[i - 1];
            num = 1;
        }
        cout << num << endl;
        ans = ans + to_string(num);
        ans = ans + temp[temp.size() - 1];
        cout << ans << endl;
        return ans;
    }
};
// @lc code=end
