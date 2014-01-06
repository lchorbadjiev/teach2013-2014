#include "shape.hh"
#include "circle.hh"
#include "rectangle.hh"
#include "point.hh"

#include <vector>
using namespace std;

int main() {


	Circle c(Point(0,0),10);
	Rectangle r(Point(0,0), Point(10,10));
	
	vector<Shape*> drawing;
	drawing.push_back(&c);
	drawing.push_back(&r);
	
	for(vector<Shape*>::iterator it=drawing.begin();
		it!=drawing.end();++it) {
		
		(*it) -> draw();	
	}
	
	return 0;
}
