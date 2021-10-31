#include"datastruct.h"
using namespace std;
class summaryranges {
private:
	map<int, int> m_map;
public:
	summaryranges() {
	}

	void addnum(int val) {
		auto right = m_map.upper_bound(val);
	}

	vector<vector<int>> getintervals() {

	}
};