#include"Datastruct.h"
using namespace std;
class TopVotedCandidate {
private:
	const static bool cmp(vector<int>& a, vector<int>& b) {
		return a[1] > b[1];
	}
	vector<vector<int>> count;
	vector<vector<int>> time;
public:
	TopVotedCandidate(vector<int>& persons, vector<int>& times) {
		for (int i = 0; i < times.size(); i++) {
			int curtime = times[i];
			bool find = false;
			for (auto& cur : count) {
				if (cur[0] == persons[i]) {
					cur[1]++;
					cur[2] = curtime;
					find = true;
					break;
				}
			}
			if (!find) {
				count.push_back({ persons[i],1 ,curtime });
			}
			sort(count.begin(), count.end(), cmp);
			int curperson = count[0][0];
			int ctime = count[0][2];
			for (int i = 0; i < count.size(); i++) {
				if (count[i][1] != count[0][1])break;
				if (count[i][2] > ctime) {
					curperson = count[i][0];
					ctime = count[i][2];
				}
			}
			time.push_back({ curtime ,curperson });
		}
	}

	int q(int t) {
		int ans = 0;
		for (auto& cur : time) {
			if (cur[0] <= t)ans = cur[1];
			else break;
		}
		return ans;
	}
};
int main() {
	vector<int> persons = { 0,0,1,1,2 };
	vector<int> times = { 0,67,69,74,87 };
	TopVotedCandidate a = TopVotedCandidate(persons, times);
	a.q(8);
}