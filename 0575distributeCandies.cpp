#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int distributeCandies(vector<int>& candyType) {//lambda
		set<int> m_set;
		for_each(candyType.begin(), candyType.end(), [&m_set](int const& cur) { m_set.insert(cur); });
		return std::min(m_set.size(), candyType.size() / 2);
	}
	int distributeCandies1(vector<int>& candyType) {//vector≥ı ºªØset
		return min(unordered_set<int>(candyType.begin(), candyType.end()).size(), candyType.size() / 2);
	}
};