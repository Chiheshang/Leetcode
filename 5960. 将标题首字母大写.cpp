#include"Datastruct.h"
using namespace std;
class Solution {
public:
    string capitalizeTitle(string title) {
        int len = 0;
        string ans = "";
        auto loc = title.find(" ");
        while (loc!=string::npos)
        {
            string temp = title.substr(0, loc);
            if (temp.size() <= 2) {
                for (char cur : temp) ans += tolower(cur);
            }
            else {
                ans += toupper(temp[0]);
                for (int i = 1; i < temp.size(); i++) {
                    ans += tolower(temp[i]);
                }
            }
            ans += " ";
            title = title.substr(loc + 1);
            loc = title.find(" ");
        }
        if (title.size() <= 2) {
            for (char cur : title) ans += tolower(cur);
        }
        else {
            ans += toupper(title[0]);
            for (int i = 1; i < title.size(); i++) {
                ans += tolower(title[i]);
            }
        }
        return ans;
    }
};