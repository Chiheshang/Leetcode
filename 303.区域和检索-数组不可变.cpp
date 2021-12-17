/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
    vector<int> num;
public:
    NumArray(vector<int>& nums) {
        int sum=0;
        for(int cur:nums){
            sum+=cur;
            num.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if(!left)return num[right];
        return num[right]-num[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

