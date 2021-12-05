#include "Datastruct.h"
using namespace std;
class Solution {
public:
	vector<int> findEvenNumbers(vector<int>& digits) {
		vector<int> num(10, 0);
		for (int cur : digits) {
			if (num[cur] == 3)continue;
			num[cur]++;
		}
		vector<int> digits_new;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < num[i]; j++) {
				digits_new.push_back(i);
			}
		}
		set<int> sor;
		for (int i = 0; i < digits_new.size(); i++) {
			for (int j = i + 1; j < digits_new.size(); j++)
			{
				for (int k = j + 1; k < digits_new.size(); k++)
				{
					sor.insert(digits_new[i] * 100 + digits_new[j] * 10 + digits_new[k]);
					sor.insert(digits_new[i] * 100 + digits_new[k] * 10 + digits_new[j]);
					sor.insert(digits_new[j] * 100 + digits_new[i] * 10 + digits_new[k]);
					sor.insert(digits_new[j] * 100 + digits_new[k] * 10 + digits_new[i]);
					sor.insert(digits_new[k] * 100 + digits_new[i] * 10 + digits_new[j]);
					sor.insert(digits_new[k] * 100 + digits_new[j] * 10 + digits_new[i]);
				}
			}
		}
		vector<int> ans;
		for (int cur : sor)
		{
			if (cur >= 100 && cur % 2 == 0)
			{
				ans.push_back(cur);
			}
		}
		return ans;
	}
};