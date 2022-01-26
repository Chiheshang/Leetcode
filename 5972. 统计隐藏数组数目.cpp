#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int numberOfArrays(vector<int>& differences, int lower, int upper) {
		int min = 0, max = 0;
		int start = 0;
		for (int cur : differences) {
			start += cur;
			min = std::min(min, start);
			max = std::max(max, start);
		}
		return std::max(upper - lower + 1 - (max - min), 0);
	}
};