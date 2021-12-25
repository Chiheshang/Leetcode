#include"Datastruct.h"
using namespace std;
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int l = 0, h = 0;
        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '0') {
                l--;
                h++;
                if (l < 0)l += 2;
            }
            else if (s[i] == '(') {
                l++;
                h++;
            }
            else {
                l--;
                h--;
                if (l < 0)l += 2;
            }
            if (h < 0)
                return false;
        }
        return l == 0;
    }
};