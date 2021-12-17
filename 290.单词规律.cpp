/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        map<char, string> m_map;
        map<string, char> m_map1;
        int index = 0;
        size_t pos = 0;
        while (index < pattern.size() - 1)
        {
            pos = s.find(" ");
            if (m_map.find(pattern[index]) != m_map.end() &&
                m_map[pattern[index]] != s.substr(0, pos))
                return false;
            if (m_map1.find(s.substr(0, pos)) != m_map1.end() &&
                m_map1[s.substr(0, pos)] != pattern[index])
                return false;
            cout<<s.substr(0, pos)<<endl;
            m_map[pattern[index]] = s.substr(0, pos);
            m_map1[s.substr(0, pos)] =pattern[index];
            cout<<pos<<endl;
            s = s.substr(pos+1);
            cout<<s<<endl;
            index++;
        }
        if (m_map.find(pattern[index]) != m_map.end() &&
            m_map[pattern[index]] != s)
            return false;
        if (m_map1.find(s) != m_map1.end() &&
                m_map1[s] != pattern[index])
                return false;    
        return true;
    }
};
// @lc code=end
