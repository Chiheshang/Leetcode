/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        if(n<=2)return n/2+1;
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=numTrees(i)*numTrees(n-i-1);
        }
        return ans;
    }
};
// @lc code=end

