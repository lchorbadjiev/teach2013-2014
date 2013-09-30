#include <iostream>
using namespace std;

#define SIZE 10

class Stack {
	int data_[SIZE];
	int top_;
public:
	Stack() {
		top_=0;
	}
	
	bool empty() {
		return top_==0;
	}
	
	bool full() {
		return top_==SIZE;
	}
	
	void push(int val) {
		if(full()) {
			cerr << "error: stack is full..." << endl;
			return;
		}
		data_[top_++]=val;
	}
	
	int pop() {
		if(empty()) {
			cerr << "error: empty stack..." << endl;
			return 0;
		}
		return data_[--top_];
	}
	
};

int main() {
	Stack st;
	cout << "empty?: " << st.empty() << endl;
	st.push(1);
	st.push(2);
	cout << "empty?: " << st.empty() << endl;
	cout << "full?: " << st.full() << endl;
	
	cout << "pop: " << st.pop() << endl;
	cout << "pop: " << st.pop() << endl;
	
	cout << "empty?: " << st.empty() << endl;
		
	return 0;
}

