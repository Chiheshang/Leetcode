#include"Datastruct.h"
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if (n < 3)return n;
        int last_one=1;
        int last_two=2;
        int ans = 0;
        for (int i = 3; i < n + 1; i++) {
            ans = last_one + last_two;
            last_two = last_one;
            last_one = ans;
        }
        return ans;
    }
};