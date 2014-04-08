#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
using namespace std;

bool gt_2_and_lt_6(int val) {
  return val > 2 && val < 6;
}


int main() {
  int a[] = {0,1,2,3,4,5,6,7,3,4};
  list<int> l(a, a+10);
  copy(l.begin(), l.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;


  list<int>::iterator last = remove_if(l.begin(), l.end(), gt_2_and_lt_6);

  copy(l.begin(), last,
       ostream_iterator<int>(cout, " "));
  cout << endl;
  cout << "l.size()=" << l.size() << endl;

  l.erase(last, l.end());

  copy(l.begin(), l.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;
  cout << "l.size()=" << l.size() << endl;



  return 0;
}
