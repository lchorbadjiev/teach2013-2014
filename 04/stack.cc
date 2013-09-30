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
			cout << "error: stack full..." << endl;
			return;
		}
		data_[top_++]=val;
	}

	int pop() {
		if(empty()) {
			cout << "error: stack empty..." << endl;
			return 0;
		}
		return data_[--top_];
	}

};

int main() {
	Stack st;
	cout << "empty? " << st.empty() << endl;
	cout << "full?  " << st.full() << endl;
	
	st.push(1);
	st.push(2);
	
	cout << st.pop() << endl;
	cout << st.pop() << endl;
	
	return 0;
}












