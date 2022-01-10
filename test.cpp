#include "Datastruct.h"
#include <fstream> 
using namespace std;
class Solution {
public:
	ListNode* remove(ListNode* root, int k) {
		if (root == nullptr)return root;
		ListNode* fast = root;
		ListNode* low = root;
		for (int i = 0; i < k; i++) {
			if (fast->next != nullptr) {
				fast = fast->next;
			}
			else {
				return nullptr;
			}
		}
		while (fast->next!=nullptr)
		{
			fast = fast->next;
			low = low->next;
		}
		low->val = low->next->val;
		low->next = low->next->next;
		return root;
	}
};
int main() {
}