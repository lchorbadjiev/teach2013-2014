#include <functional>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
using namespace std;

int main() {
  less<int> lt;

  cout << lt(3,4) << endl;
  cout << lt(3,3) << endl;
  cout << lt(3,2) << endl;

  greater<int> gt;

  cout << gt(3,2) << endl;
  cout << gt(3,3) << endl;
  cout << gt(3,4) << endl;

  greater_equal<int> ge;
  cout << ge(3,2) << endl;
  cout << ge(3,3) << endl;
  cout << ge(3,4) << endl;


  int a[]={0,1,2,3,4,5,6,7,8,9};
  list<int> l(a, a+10);
  

  replace_if(l.begin(), l.end(),
	     bind2nd(greater<int>(), 6), 
	     42);

  copy(l.begin(), l.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;

  return 0;
}
