#include"Datastruct.h"
using namespace std;
/*
* ����һ���ַ���s������s�г���Ϊ 3 �Ĳ�ͬ���������еĸ�����
������ڶ��ַ�����������ͬ�������У�����ͬ��������ֻ����һ�Ρ�
���������Ŷ��ͷ��Ŷ�һ�����ַ�����
����������ԭ�ַ���ɾ�����в����ַ���Ҳ���Բ�ɾ�����Ҳ��ı�ʣ���ַ�֮�����˳���γɵ�һ�����ַ�����
���磬"ace"��"abcde"��һ�������С�

ʾ�� 1��
���룺s = "aabca"
�����3
���ͣ�����Ϊ 3 �� 3 �����������зֱ��ǣ�
- "aba" ("aabca" ��������)
- "aaa" ("aabca" ��������)
- "aca" ("aabca" ��������)

ʾ�� 2��
���룺s = "adc"
�����0
���ͣ�"adc" �����ڳ���Ϊ 3 �Ļ��������С�

ʾ�� 3��
���룺s = "bbcbaba"
�����4
���ͣ�����Ϊ 3 �� 4 �����������зֱ��ǣ�
- "bbb" ("bbcbaba" ��������)
- "bcb" ("bbcbaba" ��������)
- "bab" ("bbcbaba" ��������)
- "aba" ("bbcbaba" ��������)

��ʾ��
3 <= s.length <= 105
s ����СдӢ����ĸ���

*/
class Solution {
public:
    int count(const string& s) {
        vector<vector<int>> letter(26);
        for (int i = 0; i < s.size(); i++) {
            letter[s[i] - 'a'].push_back(i);
        }
        unordered_set<char> set1;
        int ans = 0;
        for (auto curvec : letter) {
            set1.clear();
            if (curvec.size() <= 1)continue;
            int begin = curvec[0];
            int end = curvec[curvec.size() - 1];
            for (int i = begin; i <= end; i++) {
                set1.insert(s[i]);
            }
            ans += set1.size();
        }
        return ans;
    }
};
int main() {
    string temp = "bbcbaba";
    int a= Solution().count(temp);
    int b = 0;
    return 0;
}