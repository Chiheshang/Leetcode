/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution
{
public:
    bool deep(map<int, vector<int>>& map, vector<int> &visited, int cur)
    {
        if (find(visited.begin(),visited.end(),cur) != visited.end())
            return true;
        if (map.find(cur) == map.end())
            return true;
        visited.push_back(cur);
        for(int num:map[cur]){
            if(deep(map,visited,num))return true;
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        map<int, vector<int>> map1;
        for (auto cur : prerequisites)
        {
            map1[cur[0]].push_back(cur[1]);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (map1.find(i) != map1.end())
            {
                vector<int> visited;
                if(deep(map1, visited, i)) return false;
            }
        }
        return true;
    }
};
// @lc code=end
