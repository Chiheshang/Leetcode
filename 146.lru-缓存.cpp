/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
class LRUCache
{
private:
    int size = 0;
    map<int, vector<int>> index; // map<key,{value,time}>
public:
    LRUCache(int capacity)
    {
        size = capacity;
    }

    int get(int key)
    {
        if (index.find(key) == index.end())
            return -1;
        else
        {
            for (auto itor = index.begin(); itor != index.end(); itor++)
            {
                if (itor->first != key)
                {
                    itor->second[1]++;
                }
            }
            index[key][1]=1;
        }
        return index[key][0];
    }

    void put(int key, int value)
    {
        if(index.size()==0){
            index[key] = {value, 1};
            return;
        }
        int temp = index.begin()->first;
        int max = index.begin()->second[1];
        for (auto itor = index.begin(); itor != index.end(); itor++)
        {
            // cout<<"value:"<<itor->first<<"time"<<itor->second[1]<<endl;
            if (itor->second[1] > max)
            {
                max = itor->second[1];
                temp = itor->first;
            }
            itor->second[1]++;
        }
        // cout<<"temp:"<<temp<<endl;
        if (index.size() < size || index.find(key) != index.end())
        {
            index[key] = {value, 1};
        }
        else
        {
            index.erase(temp);
            index[key] = {value, 1};
        }
        // cout<<index.size()<<endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
