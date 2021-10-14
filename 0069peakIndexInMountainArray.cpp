#include"Datastruct.h"
using namespace std;
class Solution {
public:
	int peakIndexInMountainArray(vector<int>& arr) {//¶þ·Ö
		int left = 0;//[left,right)
		int right = arr.size();
		int ans = 0;
		while (left < right) {
			int mid = (left + right) / 2;//[left,mid),[mid,right)
			if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1]) {
				left = mid;
			}
			else if (arr[mid]<arr[mid - 1] && arr[mid]>arr[mid + 1]) {
				right = mid;
			}
			else if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
				ans = mid;
			}
		}
		return ans;
	}
};
//void trimLeftTrailingSpaces(string& input) {
//    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
//        return !isspace(ch);
//        }));
//}
//
//void trimRightTrailingSpaces(string& input) {
//    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
//        return !isspace(ch);
//        }).base(), input.end());
//}
//
//vector<int> stringToIntegerVector(string input) {
//    vector<int> output;
//    trimLeftTrailingSpaces(input);
//    trimRightTrailingSpaces(input);
//    input = input.substr(1, input.length() - 2);
//    stringstream ss;
//    ss.str(input);
//    string item;
//    char delim = ',';
//    while (getline(ss, item, delim)) {
//        output.push_back(stoi(item));
//    }
//    return output;
//}
//
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        vector<int> arr = stringToIntegerVector(line);
//
//        int ret = Solution().peakIndexInMountainArray(arr);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}