/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        map<char,vector<int>> index;
        for(int i=0;i<s.size();i++){
            index[s[i]].push_back(i);
        }
        int min=__INT32_MAX__;
        bool find=false;
        for(auto itor=index.begin();itor!=index.end();itor++){
            if(itor->second.size()!=1)continue;
            min=std::min(min,itor->second[0]);
            find=true;
        }
        return find?min:-1;
    }
};
// @lc code=end

