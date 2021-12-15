/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    bool const static cmp(vector<int> a,vector<int> b){
        return a[1]>b[1];
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> count;
        for(int cur: nums){
            count[cur]++;
        }
        vector<vector<int>> vec;
        for(auto itor=count.begin();itor!=count.end();itor++){
            vec.push_back({itor->first,itor->second});
        }
        sort(vec.begin(),vec.end(),cmp);
        vector<int> ans(k);
        for(int i=0;i<k;i++){
            ans[i]=vec[i][0];
        }
        return ans;
    }
};
// @lc code=end

