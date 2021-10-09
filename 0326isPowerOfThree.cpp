#include"Datastruct.h"
using namespace std;
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)return false;
        if (n == 1)return true;
        else if (n == 2)return false;
        else if (n % 3 == 0)return isPowerOfThree(n / 3);
        else return false;
    }
};