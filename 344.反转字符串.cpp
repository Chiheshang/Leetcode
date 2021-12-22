/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int middle=s.size()/2;
        for(int i=0;i<middle;i++){
            swap(s[i],s[s.size()-i-1]);
        }
    }
};
// @lc code=end

