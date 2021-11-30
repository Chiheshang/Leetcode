#include "Datastruct.h"
using namespace std;
class Solution {
public:
	int findNthDigit(int n) {
		if (n < 10)return n;
		long bit = 2;
		long count = 9;
		while (pow(10, bit - 1) * 9 < n) {
			bit++;
			n -= pow(10, bit - 1) * 9;
		}
		int num = pow(10, bit - 1) - 1 + n % bit;//234324 n=3  bit-n
		return  (num % ((int)pow(10, bit - n))) % 10;
	}
};