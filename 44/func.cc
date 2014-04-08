#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>
#include <list>
using namespace std;



int main() {
  less<int> lt;
  cout << lt(3, 4) << endl;
  cout << lt(5, 4) << endl;

  greater_equal<int> ge;
  cout << ge(3, 3) << endl;
  cout << ge(3, 2) << endl;
  cout << ge(3, 4) << endl;

  //lt(???, 3)
  int a[] = {0,1,2,3,4,5,6,7,8,9};
  list<int> l(a, a+10);

  copy(l.begin(), l.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;

  replace_if(l.begin(), l.end(),
	     bind2nd(less<int>(),5),
	     42);
  copy(l.begin(), l.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;


  return 0;
}
