/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> letter(26,0);
        for(char cur:t){
            letter[cur-'a']++;
        }
        for(char cur:s){
            letter[cur-'a']--;
        }
        for(int i=0;i<26;i++){
            if(letter[i]!=0)return 'a'+i;
        }
        return 'a';
    }
};
// @lc code=end

