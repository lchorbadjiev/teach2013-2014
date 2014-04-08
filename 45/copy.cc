#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
using namespace std;


int main() {
  int a[]={0,1,2,3,4,5,6,7,8,9};
  list<int> l(a, a+10);

  copy(l.begin(), l.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;

  list<int> l1(10);
  cout << "l1.size()=" << l1.size() << endl;
  copy(l.begin(), l.end(),
       l1.begin());
  copy(l1.begin(), l1.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;
  
  list<int> l2;
  cout << "l2.size()=" << l2.size() << endl;

  copy(l.begin(), l.end(), back_inserter(l2));
  copy(l.begin(), l.end(), front_inserter(l2));

  copy(l2.begin(), l2.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;
  


  return 0;
}
