/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
//#include "Datastruct.h"
class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int i = 0;
        vector<int> vec1;
        size_t pos = 0;
        while ((pos = version1.find(".")) != std::string::npos)
        {
            string cur = version1.substr(0, pos);
            vec1.push_back(atoi(cur.c_str()));
            version1.erase(0, pos + 1);
        }
        if(version1.size())vec1.push_back(atoi(version1.c_str()));
        vector<int> vec2;
        while ((pos = version2.find(".")) != std::string::npos)
        {
            string cur = version2.substr(0, pos);
            vec2.push_back(atoi(cur.c_str()));
            version2.erase(0, pos + 1);
        }
        if(version2.size())vec2.push_back(atoi(version2.c_str()));
        for (; i < vec1.size() && i < vec2.size(); i++)
        {
            if (vec1[i] < vec2[i])
                return -1;
            else if (vec1[i] > vec2[i])
                return 1;
        }
        int index1 = i, index2 = i;
        for (; index1 < vec1.size(); index1++)
        {
            if (vec1[index1])
                return 1;
        }
        for (; index2 < vec2.size(); index2++)
        {
            if (vec2[index2])
                return -1;
        }
        return 0;
    }
};
// @lc code=end
