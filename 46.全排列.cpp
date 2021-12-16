/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> & array,int val){
        if(array.size()==0){
            array.push_back({val});
            return array;
        }
        vector<vector<int>> ans;
        for(auto cur:array){
            vector<int> temp(cur);
            for(int i=0;i<cur.size()+1;i++){
                temp=cur;
                temp.insert(temp.begin()+i,val);
                ans.push_back(temp);
            }
        }
        return ans;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int cur:nums){
            ans=insert(ans,cur);
        }
        return ans;
    }
};
// @lc code=end

