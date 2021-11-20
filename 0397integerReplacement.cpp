#include"Datastruct.h"
using namespace std;
class Solution {
public:
    int integerReplacement(int n) {
        return (int)fun(n);
    }
    long fun(long n) {
        if (n == 1)return 0;
        if (n % 2 == 0)return 1 + fun(n / 2);
        else return 1 + std::min(fun(n - 1), fun(n + 1));
    }
};