/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> arrs(26);
        vector<int> arrt(26);
        for(char cur:s){
            arrs[cur-'a']++;
        }
        for(char cur:t){
            arrt[cur-'a']++;
        }
        for(int i=0;i<26;i++){
            if(arrs[i]!=arrt[i])return false;
        }
        return true;
    }
};
// @lc code=end

