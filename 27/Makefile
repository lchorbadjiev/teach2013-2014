

all: shape


point.o: point.cpp point.hh

circle.o: circle.cc circle.hh base.hh

line.o: line.cc line.hh base.hh

main.o: main.cc line.hh base.hh circle.hh point.hh

shape: main.o point.o circle.o line.o
	g++ main.o point.o circle.o line.o -o shape
	

clean:
	rm -rf *.o *~ shape a.out


