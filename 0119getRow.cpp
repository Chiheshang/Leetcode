#include"Datastruct.h"
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long cur = 1;
        for (int i = 0; i <= rowIndex; i++) {
            ans.emplace_back(cur);
            cur = cur * (rowIndex - i) / (i + 1);
        }
        return ans;
    }
};