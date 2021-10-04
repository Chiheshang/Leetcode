#include"Datastruct.h"
using namespace std;
class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        string sb;
        for (int i = 7; i >= 0; i--) {
            int val = (num >> i * 4) & 0xf;//四位四位一处理
            if (sb.size() > 0 || val > 0) {
                char cur = val < 10 ? (char)('0' + val) : (char)('a' + val - 10);
                sb.push_back(cur);
            }
        }
        return sb;
    }
};