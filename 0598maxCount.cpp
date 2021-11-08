#include"Datastruct.h"
using namespace std;
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.size() == 0)return m * n;
        int a = INT32_MAX;
        int b = INT32_MAX;
        for (auto vec : ops) {
            a = std::min(a, vec[0]);
            b = std::min(b, vec[1]);
        }
        return a * b;
    }
};