#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
  map<string, int> m;

  m["one"]=1;
  m["two"]=2;
  m["three"]=3;

  cout << "m.size()=" << m.size() << endl;
  cout << "m[one]=" << m["one"] << endl;
  cout << "m[four]=" << m["four"] << endl;
  cout << "m.size()=" << m.size() << endl;
  return 0;
}
