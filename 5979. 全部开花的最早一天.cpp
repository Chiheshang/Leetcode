#include"Datastruct.h"
using namespace std;

class Solution {
public:
	string findmax(string& input) {
		unordered_map<string, int> num;
		int index = 0;
		while (index<input.size()&&!isalnum(input[index]))
		{
			index++;
		}
		while (index < input.size())
		{
			int j = index;
			while (j < input.size() && isalpha(input[j]))
			{
				j++;
			}
			string temp = "";
			for (int i = index; i < j; i++) {
				temp += tolower(input[i]);
			}
			num[temp]++;
			while (j < input.size() && !isalpha(input[j]))
			{
				j++;
			}
			index = j;
		}
		if (num.size() == 0)return "";
		string ans = num.begin()->first;
		int max = num.begin()->second;
		for (auto itor = num.begin(); itor != num.end(); itor++) {
			if (itor->second > max) {
				max = itor->second;
				ans = itor->first;
			}
		}
		return ans;
	}
};
int main() {

}