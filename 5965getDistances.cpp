#include"Datastruct.h"
using namespace std;
class Solution {
public:
	vector<long long> getDistances(vector<int>& arr) {
		int n = arr.size();
		vector<long long> ans(n);
		map<int, long long> k, b;
		for (int i = 0; i < n; i += 1) {
			ans[i] += k[arr[i]] * i - b[arr[i]];
			k[arr[i]] += 1;
			b[arr[i]] += i;
		}
		map<int, long long> k, b;
		for (int i = n - 1; i >= 0; i -= 1) {
			ans[i] += b[arr[i]] - k[arr[i]] * i;
			k[arr[i]] += 1;
			b[arr[i]] += i;
		}

		return ans;
	}
};