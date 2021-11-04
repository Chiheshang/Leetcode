#include"Datastruct.h"
using namespace std;
class Solution {
public:
	bool isPerfectSquare(int num) {
		if (num == 1)return true;
		long cur = 1;
		for (long i = 1; i <= num / 2; i++) {
			cur = i * i;
			if (cur == num)return true;
		}
		return false;
	}
};