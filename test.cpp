#include "Datastruct.h"
using namespace std;
class Solution {
private:
	vector<string> m_vector;
	map<string, vector<int>> m_index;
public:
	int findClosest(vector<string>& words, string word1, string word2) {
		if (words != m_vector) {
			m_index.clear();
			for (int i = 0; i < words.size(); i++) {
				m_index[words[i]].push_back(i);
			}
		}
		vector<int>& vec1 = m_index[word1];
		vector<int>& vec2 = m_index[word2];
		sort(vec1.begin(), vec1.end());
		sort(vec2.begin(), vec2.end());
		int i = 0, j = 0, min = INT32_MAX;
		while (i < vec1.size() && j < vec2.size()) {
			int temp = abs(vec1[i] - vec2[j]);
			min = std::min(temp, min);
			if (vec1[i] < vec2[j])i++;
			else j++;
		}
		return min;
	}
};