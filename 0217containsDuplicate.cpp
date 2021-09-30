#include"Datastruct.h"
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> m_set;
        for (auto iter = nums.begin(); iter != nums.end(); iter++) {
            if (m_set.count(*iter) == 1) {
                return true;
            }
            else {
                m_set.insert(*iter);
            }
        }
        return false;
    }
};