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

  map<string, int>::iterator it = m.find("five");
  if(it == m.end()) {
    cout << "element not found..." << endl;
  }
  cout << "m.size()=" << m.size() << endl;


  it = m.find("two");
  if(it == m.end()) {
    cout << "element not found..." << endl;
  } else {
    cout << "element 'two' found..." << endl;
  }
  
  cout << "first: " << (*it).first << endl;
  cout << "second: " << (*it).second << endl;
  
  return 0;
}
