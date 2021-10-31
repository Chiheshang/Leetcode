#include"Datastruct.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> first = { 1 };
        ans.emplace_back(first);
        for (int i = 1; i < numRows; i++) {
            vector<int> cur_line;
            cur_line.emplace_back(1);
            for (int j = 1; j < i; j++) {
                int cur = ans[i - 1][j - 1] + ans[i - 1][j];
                cur_line.emplace_back(cur);
            }
            cur_line.emplace_back(1);
            ans.emplace_back(cur_line);
        }
        return ans;
    }
};