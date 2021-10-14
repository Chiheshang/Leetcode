#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int lengthOfLastWord(string s) {
		s.erase(s.find_last_not_of(" "));//Î²¿Õ¸ñ
		return s.size() - s.find_last_of(" ");
	}
};