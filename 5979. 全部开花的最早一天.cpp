#include"Datastruct.h"
using namespace std;
/*
* 给你一个字符串s，返回s中长度为 3 的不同回文子序列的个数。
即便存在多种方法来构建相同的子序列，但相同的子序列只计数一次。
回文是正着读和反着读一样的字符串。
子序列是由原字符串删除其中部分字符（也可以不删除）且不改变剩余字符之间相对顺序形成的一个新字符串。
例如，"ace"是"abcde"的一个子序列。

示例 1：
输入：s = "aabca"
输出：3
解释：长度为 3 的 3 个回文子序列分别是：
- "aba" ("aabca" 的子序列)
- "aaa" ("aabca" 的子序列)
- "aca" ("aabca" 的子序列)

示例 2：
输入：s = "adc"
输出：0
解释："adc" 不存在长度为 3 的回文子序列。

示例 3：
输入：s = "bbcbaba"
输出：4
解释：长度为 3 的 4 个回文子序列分别是：
- "bbb" ("bbcbaba" 的子序列)
- "bcb" ("bbcbaba" 的子序列)
- "bab" ("bbcbaba" 的子序列)
- "aba" ("bbcbaba" 的子序列)

提示：
3 <= s.length <= 105
s 仅由小写英文字母组成

*/
class Solution {
public:
    int count(const string& s) {
        vector<vector<int>> letter(26);
        for (int i = 0; i < s.size(); i++) {
            letter[s[i] - 'a'].push_back(i);
        }
        unordered_set<char> set1;
        int ans = 0;
        for (auto curvec : letter) {
            set1.clear();
            if (curvec.size() <= 1)continue;
            int begin = curvec[0];
            int end = curvec[curvec.size() - 1];
            for (int i = begin; i <= end; i++) {
                set1.insert(s[i]);
            }
            ans += set1.size();
        }
        return ans;
    }
};
int main() {
    string temp = "bbcbaba";
    int a= Solution().count(temp);
    int b = 0;
    return 0;
}