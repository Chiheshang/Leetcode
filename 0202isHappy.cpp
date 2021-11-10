#include"Datastruct.h"
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        while (true) {
            if (n == 1)return true;
            if (n == 4 || n == 16 || n == 37 || n == 58 || n == 89 || n == 145 || n == 42 || n == 21)return false;
            int raw = 0;
            while (n > 0) {
                raw += (n % 10) * (n % 10);
                n /= 10;
            }
            n = raw;
        }
    }
};