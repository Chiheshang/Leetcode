#include"Datastruct.h"
using namespace std;
class TopVotedCandidate {
private:
	const static bool cmp(vector<int, int>& a, vector<int, int>& b) {
		return a[1] < b[1];
	}
	vector<vector<int, int>> count;
	vector<vector<int, int>> time;
public:
	TopVotedCandidate(vector<int>& persons, vector<int>& times) {
		time.reserve(times.size());
		for (int i = 0; i < times.size(); i++) {
			int curtime = times[i];
			int num = -1;
			for (auto& cur : count) {
				if (cur[0] == persons[i]) {
					cur[1]++;
					num = cur[1];
					break;
				}
			}
			sort(count.begin(), count.end(), cmp);
			if (count[0][1] == num) {
				time.push_back({ curtime ,i });
			}
			else {
				time.push_back({ curtime ,count[0][0] });
			}
		}
	}

	int q(int t) {
		int ans = 0;
		for (auto cur : time) {
			if (cur[0] <= t)ans = cur[1];
			else break;
		}
		return ans;
	}
};