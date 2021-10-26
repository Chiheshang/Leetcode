#include"Datastruct.h"
using namespace std;
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createTree(nums, 0, nums.size() - 1);
    }
    TreeNode* createTree(vector<int> nums, int left, int right) {
        if (left > right)return nullptr;
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = createTree(nums, left, mid - 1);
        node->right = createTree(nums, mid + 1, right);
        return node;
    }
};