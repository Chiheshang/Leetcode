#include "Datastruct.h"
using namespace std;
class Solution {
public:
	//可以不要
	static bool compare(const vector<int> arr1, const  vector<int> arr2) {
		if (arr1[0] < arr2[0])return true;
		else return false;
	}
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), compare);
		int begin = intervals[0][0];
		int end = intervals[0][1];
		vector<vector<int>> ans;
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i][0] > end) {
				ans.push_back({ begin,end });
				begin = intervals[i][0];
				end = std::max(end, intervals[i][1]);
			}
			else {
				end = std::max(end, intervals[i][1]);
			}
		}
		ans.push_back({ begin,end });
		return ans;
	}
};