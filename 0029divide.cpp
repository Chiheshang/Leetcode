#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int divide(int dividend, int divisor) {
		bool flag = (dividend < 0) ^ (divisor < 0);
		dividend = abs(dividend);
		divisor = abs(divisor);
		if (dividend >> 1 < divisor)return flag ? -1 : 1;
		int left = 2;
	}
};