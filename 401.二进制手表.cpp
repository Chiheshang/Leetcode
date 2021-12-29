/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 */

// @lc code=start
using namespace std;
class Solution
{
public:
    int __builtin_popcount(int num){
        int ans=0;
        while (num>0)
        {
            ans+=num%2;
            num/=2;
        }
        return ans;
    }
    vector<string> readBinaryWatch(int turnedOn)
    {
        vector<string> result;
        
        for(int hours = 0; hours < 12; hours++)
        {
            for(int minute = 0; minute < 60; minute++)
            {
                string temp = "";
                if(__builtin_popcount(hours) + __builtin_popcount(minute) == turnedOn )
                {
                    temp += to_string(hours) + ":";
                    
                    if(minute < 10)
                    {
                        temp += "0";
                    }
                    temp += to_string(minute);
                    result.push_back(temp);
                }
            }
        }
        return result;
    }
};
// @lc code=end
