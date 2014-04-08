#include <algorithm>
#include <iterator>
#include <list>
#include <iostream>
using namespace std;

bool lt_3_or_gt_8(int val) {
  return val < 3 || val > 8;
}


int main() {
  int a[] = {0,1,2,3,4,5,6,7,8,9};
  list<int> l(a, a+10);

  copy(l.begin(), l.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;


  replace_if(l.begin(), l.end(), lt_3_or_gt_8, 42);
  
  copy(l.begin(), l.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;


  return 0;
}
