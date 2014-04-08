#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
  int a[]={0,1,2,3,4,5,6,7,8,9};
  vector<int> v(a, a+10);

  copy(v.begin(), v.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;

  srand(10111);

  for(int i=0; i<10; ++i) {
    random_shuffle(v.begin(), v.end());
    
    copy(v.begin(), v.end(),
	 ostream_iterator<int>(cout, " "));
    cout << endl;
  }

  return 0;
}
