#include"Datastruct.h"
using namespace std;
class Solution {
public:
    string firstPalindrome(vector<string>&words) {
        for (string cur : words) {
            string temp = cur;
            reverse(cur.begin(), cur.end());
            if (temp == cur)return temp;
        }
        return "";
    }
};