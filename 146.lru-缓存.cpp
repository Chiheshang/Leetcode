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
        return index[key][0];
    }

    void put(int key, int value)
    {
        if (index.size() < size)
        {
            index[key] = {value, 1};
        }
        else
        {
            int temp=index.begin()->first;
            int max=index[index.begin()->first][1];
            for(auto itor:index){
                if(itor.second[1]>max){
                    max=itor.second[1];
                    temp=itor.first;
                }
                itor.second[1]++;
            }
            index.erase(index.find(temp));
            index[key]={value,1};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
