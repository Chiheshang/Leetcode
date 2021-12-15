/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,bool> m_map;
        for(int cur:nums){
            if(m_map.find(cur)!=m_map.end())return cur;
            m_map[cur]=true;
        }
        return 0;
    }
};
// @lc code=end

