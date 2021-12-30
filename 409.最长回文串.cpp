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
        vector<int> letter(26,0);
        for(char cur:s){
            letter[cur-'A']++;
        }
        int res=0;
        bool tag=false;
        for(auto x:letter){
            if(x%2==1)tag
        }
    }
};
// @lc code=end
