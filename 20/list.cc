#include <iostream>
using namespace std;

class ListError {};
class List {
	struct Node {
		int data_;
		Node* next_;
		Node* prev_;
		
		Node(int val)
		: data_(val),
		  next_(0),
		  prev_(0)
		{}
	};
	
	Node* head_;
public:
	List()
	: head_(new Node(42))
	{
		head_->next_ = head_->prev_ = head_;
	}

	~List() {
		while(!empty()) {
			pop_front();
		}
		delete head_;
	}

	bool empty() const {
		return head_==head_->next_;
	}

	void push_front(int val) {
		Node* ptr=new Node(val);
		Node* front=head_->next_;
		
		head_->next_=ptr;
		ptr->prev_=head_;
		
		ptr->next_=front;
		front->prev_=ptr;
	}
	
	void push_back(int val) {
		//???????
		Node* ptr=new Node(val);
		Node* back=head_->prev_;
		
		head_->prev_=ptr;
		ptr->next_=head_;
		
		ptr->prev_=back;
		back->next_=ptr;
	}
	
	
	int front() const {
		if(empty()) {
			throw ListError();
		}
		return head_->next_->data_;
	}
	
	int back() const {
		if(empty()) {
			throw ListError();
		}
		return head_->prev_->data_;
	}
	
	void pop_front() {
		if(empty()) {
			throw ListError();
		}
	
		Node* front=head_->next_;
		Node* new_front=front->next_;
		
		head_->next_=new_front;
		new_front->prev_=head_;
		
		delete front;
	}
	
	void pop_back() {
		//?????
		
	}
};


int main() {
	List ls;
	cout << "ls.empty()? " << ls.empty() << endl;
	ls.push_front(1);
	cout << "ls.empty()? " << ls.empty() << endl;
	ls.push_front(0);
	cout << "ls.front(): " << ls.front() << "; "
		<< "ls.back(): " << ls.back() << endl;
	ls.push_back(2);
	cout << "ls.front(): " << ls.front() << "; "
		<< "ls.back(): " << ls.back() << endl;
	ls.pop_front();
	cout << "ls.front(): " << ls.front() << "; "
		<< "ls.back(): " << ls.back() << endl;
	
	return 0;
}







