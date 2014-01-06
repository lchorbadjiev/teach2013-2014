

all: draw
	./draw

point.o: point.cc point.hh
circle.o: circle.cc circle.hh shape.hh point.hh
rectangle.o: rectangle.cc



draw: point.o circle.o rectangle.o main.o
	g++ -o draw point.o circle.o rectangle.o main.o



clean:
	rm -f *.o draw *~

