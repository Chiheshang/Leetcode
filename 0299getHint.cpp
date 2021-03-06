#include"Datastruct.h"
using namespace std;
class Solution {
public:
	string getHint(string secret, string guess) {
		int numA = 0, numB = 0;
		map<int, int> num_coutA;
		for (int i = 0; i < secret.size(); i++) {
			int a = secret[i] - '0';
			int b = guess[i] - '0';
			if (a == b) {
				numA++;
			}
			else {
				num_coutA[a]++;
			}
		}
		for (int i = 0; i < secret.size(); i++) {
			int a = secret[i] - '0';
			int b = guess[i] - '0';
			if (a == b) {
				continue;
			}
			if (num_coutA[b] > 0) {
				numB++;
				num_coutA[b]--;
			}
		}
		
		string ans = "";
		ans = ans + to_string(numA) + "A" + to_string(numB) + "B";
		return ans;
	}
};
//
//string stringToString(string input) {
//	string result;
//	for (int i = 1; i < input.length() - 1; i++) {
//		char currentChar = input[i];
//		if (input[i] == '\\') {
//			char nextChar = input[i + 1];
//			switch (nextChar) {
//			case '\"': result.push_back('\"'); break;
//			case '/': result.push_back('/'); break;
//			case '\\': result.push_back('\\'); break;
//			case 'b': result.push_back('\b'); break;
//			case 'f': result.push_back('\f'); break;
//			case 'r': result.push_back('\r'); break;
//			case 'n': result.push_back('\n'); break;
//			case 't': result.push_back('\t'); break;
//			default: break;
//			}
//			i++;
//		}
//		else {
//			result.push_back(currentChar);
//		}
//	}
//	return result;
//}
//
//int main() {
//	string line;
//	while (getline(cin, line)) {
//		string secret = stringToString(line);
//		getline(cin, line);
//		string guess = stringToString(line);
//
//		string ret = Solution().getHint(secret, guess);
//
//		string out = (ret);
//		cout << out << endl;
//	}
//	return 0;
//}