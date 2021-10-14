#include"Datastruct.h"
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int index = digits.size() - 1;
		while (index >= 0) {
			if (digits[index] < 9) {
				digits[index]++;
				break;
			}
			else {
				digits[index] = 0;
				index--;
			}
		}
		if (index >= 0)return digits;
		else {
			digits.insert(digits.begin(), 1);
			return digits;
		}
	}
};