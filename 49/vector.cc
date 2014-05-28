#include <iostream>
#include <exception>
using namespace std;


template<typename T>
class Vector {
  const static int CHUNK_SIZE = 10;

  int capacity_;
  int size_;
  T* buffer_;

  void ensure_capacity(int count) {
    if(size_ + count < capacity_) {
      return;
    }

    T* old_buffer = buffer_;
    capacity_ += (count/CHUNK_SIZE + 1) * CHUNK_SIZE;
    // cout << "ensure capacity to: " << capacity_ << endl;

    buffer_ = new T[capacity_];

    for(int i=0;i<size_;++i) {
      buffer_[i] = old_buffer[i];
    }

    delete [] old_buffer;
  }

public:
  
  Vector(int capacity)
    : capacity_(capacity),
      size_(0),
      buffer_(new T[capacity_])
  {}

  ~Vector() {
    delete [] buffer_;
  }

  int size() const {
    return size_;
  }

  bool empty() const {
    return size_ == 0;
  }

  void clear() {
    size_ = 0;
  }

  int capacity() const {
    return capacity_;
  }

  void push_back(const T& val) {
    ensure_capacity(1);
    buffer_[size_++] = val;
  }

  void pop_back() {
    if(empty()) {
      throw exception();
    }
    size_--;
  }

  T& front() {
    if(empty()) {
      throw exception();
    }
    return buffer_[0];
  }

  const T& front() const {
    if(empty()) {
      throw exception();
    }
    return buffer_[0];
  }

  T& back() {
    if(empty()) {
      throw exception();
    }
    return buffer_[size_-1];
  }

  const T& back() const {
    if(empty()) {
      throw exception();
    }
    return buffer_[size_-1];
  }

  T& operator[](int index) {
    return buffer_[index];
  }

  T& at(int index) {
    if(index<0 || index >= size_) {
      throw exception();
    }
    return buffer_[index];
  }


  class iterator {
    friend class Vector;

    Vector& v_;
    int pos_;

    iterator(Vector& v, int pos) 
      : v_(v), pos_(pos)
    {}
  public:

    iterator operator++() {
      if(pos_<v_.size()) {
	++pos_;
      }
      return *this;
    }

    iterator operator++(int) {
      iterator res = *this;
      if(pos_<v_.size()) {
	++pos_;
      }
      return res;
    }

    bool operator==(const iterator& other) const {
      return pos_ == other.pos_;
    }

    bool operator!=(const iterator& other) const {
      return ! operator==(other);
    }

    T& operator*() {
      return v_[pos_];
    }

  };

  iterator begin() {
    return iterator(*this, 0);
  }

  iterator end() {
    return iterator(*this, size_);
  }

};

int main() {
  Vector<int> v(5);

  cout << "v.size()=" << v.size() << endl;
  cout << "v.capacity()=" << v.capacity() << endl;
  cout << "v.empty()=" << v.empty() << endl;

  v.push_back(1);
  v.push_back(2);

  cout << "v.size()=" << v.size() << endl;
  cout << "v.capacity()=" << v.capacity() << endl;
  cout << "v.empty()=" << v.empty() << endl;

  for(int i=0; i<77; i++) {
    v.push_back(i);
  }

  cout << "v.size()=" << v.size() << endl;
  cout << "v.capacity()=" << v.capacity() << endl;

  for(int i=0; i<30; i++) {
    v.pop_back();
  }

  cout << "v.size()=" << v.size() << endl;
  cout << "v.capacity()=" << v.capacity() << endl;

  cout << "v.front()=" << v.front() << endl;
  cout << "v.back()=" << v.back() << endl;
  v.back()=50;
  cout << "v.back()=" << v.back() << endl;

  const Vector<int>& vv = v;
  cout << "vv.back()=" << vv.back() << endl;

  // vv.back()=42;
  // cout << "vv.back()=" << vv.back() << endl;

  for(int i=0; i< v.size(); ++i) {
    v[i]=i;
  }

  for(int i=0; i< v.size(); ++i) {
    cout << v[i] << ' ';
  }
  cout << endl;

  // Vector<int>::iterator it1 = v.begin();

  for(Vector<int>::iterator it=v.begin(); it!=v.end(); it++) {
    cout << (*it) << ' ';
  }
  cout << endl;

  Vector<int>::iterator it = v.begin();



  return 0;
}


