#include"Datastruct.h"
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
		unordered_map<char, int> map;
		map.insert(make_pair('I', 1));
		map.insert(make_pair('V', 5));
		map.insert(make_pair('X', 10));
		map.insert(make_pair('L', 50));
		map.insert(make_pair('C', 100));
		map.insert(make_pair('D', 500));
		map.insert(make_pair('M', 1000));
		string ans="";
		while (num > 999) {
			num -= 1000;
			ans = ans + "M";
		}
		if (num > 899) {
			num -= 900;
			ans = ans + "CM";
		}
		if (num > 499) {
			num -= 500;
			ans = ans + "D";
		}
		if (num > 399) {
			num -= 400;
			ans = ans + "CD";
		}
		while (num > 99) {
			num -= 100;
			ans = ans + "C";
		}
		if (num > 89) {
			num -= 90;
			ans = ans + "XC";
		}
		if (num > 49) {
			num -= 50;
			ans = ans + "L";
		}
		if (num > 39) {
			num -= 40;
			ans = ans + "XL";
		}
		while (num > 9) {
			num -= 10;
			ans = ans + "X";
		}
		if (num > 8) {
			num -= 9;
			ans = ans + "IX";
		}
		if (num > 4) {
			num -= 5;
			ans = ans + "V";
		}
		if (num > 3) {
			num -= 4;
			ans = ans + "IV";
		}
		while (num > 0) {
			num -= 1;
			ans = ans + "I";
		}
		return ans;
    }
};