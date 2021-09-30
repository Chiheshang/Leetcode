#include"Datastruct.h"
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int max = 0;
        while (left < right) {
            max = std::max(max, (int)(right - left) * std::min(height[left], height[right]));
            if (height[left] > height[right])right--;
            else left++;
        }
        return max;
    }
};