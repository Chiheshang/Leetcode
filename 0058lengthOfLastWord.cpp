#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int lengthOfLastWord(string s) {
		s.erase(s.find_last_not_of(" "));//Î²¿Õ¸ñ
		return s.size() - s.find_last_of(" ");
	}
};
struct item
{
public:
	int i ;
	char c ;
	item(int i, char c) {
		this->i = i;
		this->c = c;
	}
};
//int main() {
//	item* array[3];
//	for (int i = 0; i < 3; i++) {
//		array[i] = new item(0, '3');
//	}
//	cout << array[0]->c << endl;
//}