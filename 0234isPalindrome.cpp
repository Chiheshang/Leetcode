#include"Datastruct.h"
using namespace std;
class Solution {
public:
	ListNode* reverseList(ListNode* root) {
		if (!root || !root->next)return root;
		ListNode* pre = nullptr;
		ListNode* next = nullptr;
		while (root)
		{
			next = root->next;
			root->next = pre;
			pre = root;
			root = next;
		}
		return pre;
	}
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next)return head;
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast->next && fast->next->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* temp = slow->next;
		slow->next = nullptr;
		slow = temp;
		slow = reverseList(slow);
		while (slow && head) {
			if (slow->val != head->val)return false;
			slow = slow->next;
			head = head->next;
		}
		return true;
	}
};
void trimLeftTrailingSpaces(string& input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
		}));
}

void trimRightTrailingSpaces(string& input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
		}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

ListNode* stringToListNode(string input) {
	// Generate list from the input
	vector<int> list = stringToIntegerVector(input);

	// Now convert that list into linked list
	ListNode* dummyRoot = new ListNode(0);
	ListNode* ptr = dummyRoot;
	for (int item : list) {
		ptr->next = new ListNode(item);
		ptr = ptr->next;
	}
	ptr = dummyRoot->next;
	delete dummyRoot;
	return ptr;
}

string boolToString(bool input) {
	return input ? "True" : "False";
}

int main() {
	string line;
	while (getline(cin, line)) {
		ListNode* head = stringToListNode(line);

		bool ret = Solution().isPalindrome(head);

		string out = boolToString(ret);
		cout << out << endl;
	}
	return 0;
}