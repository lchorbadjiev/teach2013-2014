#include <iostream>
using namespace std;

class StackError{};

class Stack {
	struct Node {
		int data_;
		Node* next_;
		
		Node(int data)
		: data_(data),
		  next_(0)
		{}
			
	};
	
	Node* top_;
public:
	Stack()
	: top_(0)
	{}
	
	bool empty() const {
		return top_==0;
	}

	void push(int val) {
		Node* node=new Node(val);
		node->next_=top_;
		top_=node;
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
	
	~Stack() {
		//????
		while(!empty()) {
			pop();
		}
	}
};


int main() {
	Stack st;
	cout << "st.empty()? " << st.empty() << endl;
	for(int i=0;i<10;i++) {
		st.push(i);
	}
	cout << "st.empty()? " << st.empty() << endl;
	while(!st.empty()) {
		cout << "st.pop(): " << st.pop() << endl;
	}
	
	return 0;
}







