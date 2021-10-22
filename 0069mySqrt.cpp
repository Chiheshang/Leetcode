#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int mySqrt(int x) {//¶þ·Ö
		if (x <= 1)return x;
		int ans = 0;
		int left = 0;
		int right = x / 2 + 1;
		while (left < right) {
			int mid = (left + right) / 2;
			if (x / (mid + 1) < mid + 1 && x / mid >= mid) {
				ans = mid;
				break;
			}
			else if (x / mid < mid) {
				right = mid;
			}
			else if (x / mid > mid) {
				left = mid + 1;
			}
		}
		return ans;
	}
};

//int stringToInteger(string input) {
//	return stoi(input);
//}
//
//int main() {
//	string line;
//	while (getline(cin, line)) {
//		int x = stringToInteger(line);
//
//		int ret = Solution().mySqrt(x);
//
//		string out = to_string(ret);
//		cout << out << endl;
//	}
//	return 0;
//}