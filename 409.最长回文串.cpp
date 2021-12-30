/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution
{
public:
    int longestPalindrome(string s)
    {
        vector<int> dp(s.size());
        for (int i = 0; i < s.size(); i++)
        {
            if (i <= 1)
            {
                dp[i] = 1;
                continue;
            }
            cout<<"i-2*dp[i-1]:"<<i-2*dp[i-1]<<endl;
            if(s[i]==s[i-2*dp[i-1]])dp[i]=dp[i-1]+1;
            else dp[i]=1;
            cout<<"dp[i]:"<<dp[i]<<endl;
        }
        return dp[s.size()-1];
    }
};
// @lc code=end
