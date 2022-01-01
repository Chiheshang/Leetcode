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
        map<char,int>letter;
        for(char cur:s){
            cout<<cur-'A'<<endl;
            letter[cur-'A']++;
        }
        int res=0;
        bool tag=false;
        for(auto cur:letter){
            int x=cur.second;
            if(x%2==1)tag=true;
            res+=x/2*2;
        }
        if(tag) res++;
        return res;
    }
};
// @lc code=end
