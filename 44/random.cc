#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main() {
  int a[]={1,2,3,4,5,6};
  vector<int> l(a, a+6);
  copy(l.begin(), l.end(), 
       ostream_iterator<int>(cout, " "));
  cout << endl;

  for(int i=0; i<10; i++) {

    random_shuffle(l.begin(), l.end());

    copy(l.begin(), l.end(), 
	 ostream_iterator<int>(cout, " "));
    cout << endl;
  }

  return 0;
}
