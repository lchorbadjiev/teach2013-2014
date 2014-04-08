#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>

using namespace std;


bool lt_3_or_gt_7(int val) {
  return val < 3 || val > 7;
}

int main() {
  int a[] = {0,1,2,3,4,5,6,7,8,9};
  list<int> l(a, a+10);
  
  copy(l.begin(), l.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;

  list<int>::iterator last = remove_if(l.begin(), l.end(), lt_3_or_gt_7);
  copy(l.begin(), last,
       ostream_iterator<int>(cout, " "));
  cout << endl;
  cout << "l.size()=" << l.size() << endl;

  l.erase(last, l.end());
  cout << "l.size()=" << l.size() << endl;
  copy(l.begin(), l.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;

  return 0;
}
