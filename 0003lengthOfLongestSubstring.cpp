#include"Datastruct.h"
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int left = 0, right = 0;
        unordered_set<char> m_set;
        while (right < s.size()) {
            if (!m_set.count(s[right])) {
                m_set.insert(s[right]);
                max = std::max(max, (int)m_set.size());
            }
            else {
                while (s[left] != s[right]) {
                    m_set.erase(s[left]);
                    left++;
                }
                left++;
            }
            right++;
        }
        return max;
    }
};