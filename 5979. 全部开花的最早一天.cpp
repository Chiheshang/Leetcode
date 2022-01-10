#include"Datastruct.h"
using namespace std;
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int min_growTime = growTime[0];
        int min_plantTime = plantTime[0];
        int max_growTime = growTime[0];
        int ans_plantTime = 0;
        int ans_growTime = 0;
        for (int cur : plantTime) {
            min_plantTime = std::min(min_plantTime, cur);
            max_growTime = std::max(max_growTime, cur);
            ans_plantTime += cur;
        }
        for (int cur : growTime) {
            min_growTime = std::min(min_growTime, cur);
            ans_growTime += cur;
        }
        ans_plantTime += min_growTime;
        ans_growTime -= max_growTime;
        ans_growTime += min_plantTime;
        return std::min(ans_plantTime, ans_growTime);
    }
};
int main() {
    vector<int> a = { 15,15,21,19,22,27,3,18,19,16,15,22 };
    int sum = 0;
    for (int cur : a) {
        sum += cur;
    }
    int i = 0;
}
/*
* [27,5,24,17,27,4,23,16,6,26,13,17,21,3,9,10,28,26,4,10,28,2]
[26,9,14,17,6,14,23,24,11,6,27,14,13,1,15,5,12,15,23,27,28,12]
* 
* [24,28,9,1,9,27,10,10,1,4,29,29]
[15,15,21,19,22,27,3,18,19,16,15,22]
* 
* 
*/