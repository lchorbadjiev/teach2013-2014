#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void error(const char* msg) {
  cerr << msg << endl;
  exit(1);
}

int main(int argc, char* argv[]) {
  if(argc!=3) {
    error("bad number of arguments...");
  }

  ifstream in(argv[1]);
  if(!in) {
    error("bad source file...");
  }

  ofstream out(argv[2]);//, ios_base::out|ios_base::app);
  if(!out) {
    error("bad destination file...");
  }

  char ch;
  while(in.get(ch)) {
    out.put(ch);
  }
  
  return 0;
}
