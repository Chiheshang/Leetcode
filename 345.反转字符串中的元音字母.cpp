/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vowel;
        map<char,bool> flag;
        flag['a']=true;
        flag['e']=true;
        flag['i']=true;
        flag['o']=true;
        flag['u']=true;
        flag['A']=true;
        flag['E']=true;
        flag['I']=true;
        flag['O']=true;
        flag['U']=true;
        for(auto cur:s){
            if(flag.find(cur)!=flag.end())vowel.push_back(cur);
        }
        int middle=vowel.size()/2;
        for(int i=0;i<middle;i++){
            swap(vowel[i],vowel[vowel.size()-1-i]);
        }
        int index=0;
        for(int i=0;i<s.size();i++){
            if(flag.find(s[i])!=flag.end())
                s[i]=vowel[index++];
        }
        return s;
    }
};
// @lc code=end

