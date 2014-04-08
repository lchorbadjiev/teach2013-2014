#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <iterator>
using namespace std;



int main() {
  int a[] = {0,1,2,3,4,5,6,7,8,9};
  list<int> l(a, a+10);
  vector<int> v(10);


  copy(l.begin(), l.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;
  cout << "v.size()=" << v.size() << endl;
  copy(l.begin(), l.end(),
       v.begin());
  
  copy(v.begin(), v.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;


  vector<int> v1;
  cout << "v1.size()=" << v1.size() << endl;
  copy(l.begin(), l.end(),
       back_inserter(v1));
  // copy(l.begin(), l.end(),
  //      front_inserter(v1));
  copy(l.begin(), l.end(),
       back_inserter(v1));
  copy(v1.begin(), v1.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;

  
  return 0;
}


