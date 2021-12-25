#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int mostWordsFound(vector<string>& sentences) {
		int max = 0;
		for (string cur : sentences)
		{
			if (cur.size() == 0)continue;
			int num = 0;
			int index = cur.find(" ");
			while (index != string::npos)
			{
				num++;
				cur = cur.substr(index + 1);
				index = cur.find(" ");
			}
			max = std::max(max, num + 1);
		}
		return max;
	}
};
int main()
{
	vector<string> sentences = { "alice and bob love leetcode","i think so too","this is great thanks very much" };
	Solution().mostWordsFound(sentences);
}