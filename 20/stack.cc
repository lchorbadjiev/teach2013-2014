#include <iostream>
using namespace std;

class StackError{};

class Stack {
	struct Node {
		int data_;
		Node* next_;
		
		Node(int val)
		: data_(val),
		  next_(0)
		{}
	};

	Node* top_;
public:
	Stack() 
	: top_(0)
	{}
	
	~Stack() {
		//?????
		while(!empty()) {
			pop();
		}
	}
	
	bool empty() const {
		return top_==0;
	}

	void push(int val) {
		Node* ptr=new Node(val);
		ptr->next_=top_;
		top_=ptr;
	}

	int pop() {
		if(empty()) {
			throw StackError();
		}
		Node* ptr=top_;
		top_=top_->next_;
		
		int res=ptr->data_;
		delete ptr;
		
		return res;
	}
};

int main() {
	Stack st;
	cout << "st.empty()? " << st.empty() << endl;
	st.push(1);
	cout << "st.empty()? " << st.empty() << endl;
	cout << "st.pop(): " << st.pop() << endl;
	cout << "st.empty()? " << st.empty() << endl;
	
	return 0;
}

