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
	
	class iterator {
		friend class List;
	
		Node* current_;
		
		iterator(Node* current)
		: current_(current)
		{}
	public:
		iterator& operator++() {
			current_=current_->next_;
			return *this;
		}
		iterator operator++(int) {
			iterator res=*this;
			current_=current_->next_;
			
			return res;
		}
		
		int& operator*() {
			return current_->data_;
		}
		
		bool operator==(const iterator& other) const {
			return current_==other.current_;
		}
		
		bool operator!=(const iterator& other) const {
			return ! operator==(other);
		}
		
	};
	
	iterator begin() const {
		return iterator(head_->next_);
	}
	
	iterator end() const {
		return iterator(head_);
	}
	
	iterator insert(iterator pos, int val) {
		Node* node=new Node(val);
		Node* curr=pos.current_;
		
		Node* prev=curr->prev_;
		
		prev->next_=node;
		node->prev_=prev;
		
		node->next_=curr;
		curr->prev_=node;
		
		return iterator(node);
	}
	
	
	iterator erase(iterator pos) {
		Node* curr=pos.current_;
		
		Node* next=curr->next_;
		Node* prev=curr->prev_;
		
		prev->next_=next;
		next->prev_=prev;
		
		delete curr;
		
		return iterator(next);
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
	
	List::iterator it=ls.begin();

	it++;
	
	
	*it;
	*it=42;

	it!=ls.end();
	
	
	ls.insert(ls.begin(),-42);
	ls.insert(ls.end(),42);
	
	for(List::iterator i=ls.begin();i!=ls.end();++i) {
		cout << (*i) << ' ';
	}
	cout << endl;
	
	
	ls.erase(ls.begin());
	//ls.erase(--ls.end());
	
	for(List::iterator i=ls.begin();i!=ls.end();++i) {
		cout << (*i) << ' ';
	}
	cout << endl;
	
	
	
	return 0;
}







