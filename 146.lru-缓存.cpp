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
    }

    void put(int key, int value)
    {
        if (index.size() < size)
        {
            index[key] = {value, 1};
        }
        else
        {
            int temp=index[index.begin()->first]
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
