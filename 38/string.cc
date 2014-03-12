#include <string.h>

#include <iostream>
using namespace std;

class String {

	int capacity_;
	int size_;
	char* buffer_;


	void ensure_capacity(int cap) {
		if(capacity_ >= cap) {
			return;
		}
		char* tmp = buffer_;
		capacity_ = cap;
		buffer_ = new char[capacity_];
		strcpy(buffer_, tmp);
		delete [] tmp;
	}

	friend ostream& operator<<(ostream&, const String&);
	
public:

	String(int capacity)
	: capacity_(capacity),
	  size_(0),
	  buffer_(new char[capacity_])
	{
		buffer_[0]='\0';
	}
	
	~String() {
		delete [] buffer_;
	}
	
	
	String(const char* str)
	: capacity_(0),
	  size_(0),
	  buffer_(0)
	{
		size_ = strlen(str);
		capacity_ = size_ + 1;
		buffer_ = new char[capacity_];
		strcpy(buffer_, str);
	}
	
	
	String& operator+=(const String& s) {
		ensure_capacity(size_+s.size_+1);
		strcat(buffer_, s.buffer_);
		return *this;
	}
};


ostream& operator<<(ostream& out, const String& s) {
	out << s.buffer_;
	return out;
}

int main() {
	String s1("Hello");
	String s2("World!");

	cout << s1 << endl;
	cout << s2 << endl;
	s1+=s2;
	cout << s1 << endl;
	return 0;
}

