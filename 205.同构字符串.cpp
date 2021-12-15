/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> k_v;
        map<char,char> v_k;
        for(int i=0;i<s.size();i++){
            if(k_v.find(s[i])!=k_v.end()&&k_v[s[i]]!=t[i])return false;
            if(v_k.find(t[i])!=v_k.end()&&v_k[t[i]]!=s[i])return false;
            k_v[s[i]]=t[i];
            v_k[t[i]]=s[i];
        }
        return true;
    }
};
// @lc code=end

