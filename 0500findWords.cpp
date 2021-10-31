#include"Datastruct.h"
using namespace std;
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char, int> index;
        string first = "qwertyuiopQWERTYUIOP";
        string second = "asdfghjklASDFGHJKL";
        string third = "zxcvbnmZXCVBNM";
        for (char cur : first) {
            index.insert(make_pair(cur, 1));
        }
        for (char cur : second) {
            index.insert(make_pair(cur, 2));
        }
        for (char cur : third) {
            index.insert(make_pair(cur, 3));
        }
        vector<string> ans;
        for (string cur_str : words) {
            int i = index.find(cur_str[0])->second;
            bool find = true;
            for (char cur_letter : cur_str) {
                find = (index.find(cur_letter)->second == i);
                if (!find)break;
            }
            if (find) {
                ans.emplace_back(cur_str);
            }
        }
        return ans;
    }
};
//int main() {
//    vector<string> a;
//    a.emplace_back("Peace");
//    Solution().findWords(a);
//    return 0;
//}