#include"Datastruct.h"
using namespace std;
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        unordered_map<string, int> ind;
        unordered_set<string> index;
        vector<int> letter(26);
        for (string& cur : words) {
            if (cur[0] == cur[1]) {
                letter[cur[0] - 'a']++;
                continue;
            }
            if (ind[cur]) {
                ans += 4;
                ind[cur]--;
            }
            else
            {
                swap(cur[0], cur[1]);
                ind[cur]++;
            }
        }
        bool tag = false;
        for (int cur : letter) {
            if (cur % 2 == 1) {
                ans += (cur - 1) * 2;
                tag = true;
            }
            else{
                ans += cur * 2;
            }
        }
        if (tag)ans += 2;
        return ans;
    }
};