#include"Datastruct.h"
using namespace std;
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		map<int, int> count;
		vector<int>ans;
		for (int cur : nums) {
			auto iter = count.find(cur);
			if (iter != count.end()) {
				iter->second++;
				if (iter->second > nums.size() / 3 && iter->second <= nums.size() / 3 + 1) {
					ans.emplace_back(cur);
				}
			}
			else {
				count.insert(make_pair(cur, 1));
				if (1 > nums.size() / 3 && 1 <= nums.size() / 3 + 1) {
					ans.emplace_back(cur);
				}
			}
		}
		return ans;
	}
    vector<int> majorityElement1(vector<int>& nums) {//Ħ��ͶƱ��
        vector<int> ans;
        int element1 = 0;
        int element2 = 0;
        int vote1 = 0;
        int vote2 = 0;

        for (auto& num : nums) {
            if (vote1 > 0 && num == element1) { //�����Ԫ��Ϊ��һ��Ԫ�أ��������1
                vote1++;
            }
            else if (vote2 > 0 && num == element2) { //�����Ԫ��Ϊ�ڶ���Ԫ�أ��������1
                vote2++;
            }
            else if (vote1 == 0) { // ѡ���һ��Ԫ��
                element1 = num;
                vote1++;
            }
            else if (vote2 == 0) { // ѡ��ڶ���Ԫ��
                element2 = num;
                vote2++;
            }
            else { //�������Ԫ�ؾ�����ͬ�����໥����1��
                vote1--;
                vote2--;
            }
        }

        int cnt1 = 0;
        int cnt2 = 0;
        for (auto& num : nums) {
            if (vote1 > 0 && num == element1) {
                cnt1++;
            }
            if (vote2 > 0 && num == element2) {
                cnt2++;
            }
        }
        // ���Ԫ�س��ֵĴ����Ƿ�����Ҫ��
        if (vote1 > 0 && cnt1 > nums.size() / 3) {
            ans.push_back(element1);
        }
        if (vote2 > 0 && cnt2 > nums.size() / 3) {
            ans.push_back(element2);
        }

        return ans;
    }
};