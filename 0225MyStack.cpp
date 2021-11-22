#include"Datastruct.h"
using namespace std;
class MyStack {
public:
	queue<int>* quene1;
	queue<int>* quene2;
	MyStack() {
		quene1 = new queue<int>();
		quene2 = new queue<int>();
	}

	void push(int x) {
		quene1->push(x);
	}

	int pop() {
		while (quene1->size()>1)
		{
			quene2->push(quene1->front());
			quene1->pop();
		}
		int pop = quene1->front();
		quene1->pop();
		swap(quene1, quene2);
		return pop;
	}

	int top() {
		while (quene1->size() > 1)
		{
			quene2->push(quene1->front());
			quene1->pop();
		}
		int pop = quene1->front();
		quene2->push(pop);
		quene1->pop();
		swap(quene1, quene2);
		return pop;
	}

	bool empty() {
		return(quene1->empty());
	}
};
