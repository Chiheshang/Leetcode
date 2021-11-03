#include"Datastruct.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int size = nums.size();
        if (size < 3)   return {};          
        vector<vector<int> >ans;            
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < size; i++)      // �̶���һ������ת��Ϊ������֮��
        {
            if (nums[i] > 0)    return ans; 
            if (i > 0 && nums[i] == nums[i - 1])  continue;
            // ˫ָ����nums[i]�����������Ѱ�Һ�Ϊ0-nums[i]������������
            int left = i + 1;
            int right = size - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > -nums[i])
                    right--;    // ����֮��̫����ָ������
                else if (nums[left] + nums[right] < -nums[i])
                    left++;     // ����֮��̫С����ָ������
                else
                {
                    // �ҵ�һ����Ϊ�����Ԫ�飬��ӵ�����У�����ָ������������Ѱ��
                    ans.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    // ȥ�أ��ڶ������͵�������Ҳ���ظ�ѡȡ
                    // ���磺[-4,1,1,1,2,3,3,3], i=0, left=1, right=5
                    while (left < right && nums[left] == nums[left - 1])  left++;
                    while (left < right && nums[right] == nums[right + 1])    right--;
                }
            }
        }
        return ans;
    }
};