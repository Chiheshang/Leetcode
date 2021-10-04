#include"Datastruct.h"
using namespace std;
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        if (s.empty()) {
            return "";
        }
        string ans;
        int length = 0;
        for (int index = s.size() - 1; index >= 0; index--) {
            if (s[index] == '-') {
                continue;
            }
            ans.push_back((toupper(s[index])));
            length++;
            if (length % k == 0 ) {
                ans.push_back('-');
            } 
        }
        reverse(ans.begin(), ans.end());
        if (ans[0] == '-') {
            ans.erase(0, 1);
        }
        return ans;
    }
};
//string stringToString(string input) {
//    string result;
//    for (int i = 1; i < input.length() - 1; i++) {
//        char currentChar = input[i];
//        if (input[i] == '\\') {
//            char nextChar = input[i + 1];
//            switch (nextChar) {
//            case '\"': result.push_back('\"'); break;
//            case '/': result.push_back('/'); break;
//            case '\\': result.push_back('\\'); break;
//            case 'b': result.push_back('\b'); break;
//            case 'f': result.push_back('\f'); break;
//            case 'r': result.push_back('\r'); break;
//            case 'n': result.push_back('\n'); break;
//            case 't': result.push_back('\t'); break;
//            default: break;
//            }
//            i++;
//        }
//        else {
//            result.push_back(currentChar);
//        }
//    }
//    return result;
//}
//
//int stringToInteger(string input) {
//    return stoi(input);
//}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int k = stringToInteger(line);

        string ret = Solution().licenseKeyFormatting(s, k);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}