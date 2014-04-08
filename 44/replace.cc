#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
using namespace std;

bool less_than_4(int val) {
  return val < 4;
}


int main() {
  int a[] = {0,1,2,3,4,5,6,7,8,9};
  list<int> l(a, a+10);
  
  copy(l.begin(), l.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;

  replace_if(l.begin(), l.end(), 
	     less_than_4,
	     42);

  copy(l.begin(), l.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;


  return 0;
}
