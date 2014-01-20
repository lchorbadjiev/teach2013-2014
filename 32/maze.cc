#include <vector>
#include <iostream>
using namespace std;

enum Direction {
	NONE = 0,
	DOWN = 1,    // 0001
	RIGHT = 1<<1,// 0010
	TOP = 1<<2,  // 0100
	LEFT = 1<<3  // 1000
// 0001
// 1111
// 1010
};

class Cell {
	unsigned walls_;
	unsigned row_;
	unsigned col_;
public:

	Cell(int row, int col)
	: walls_(DOWN|RIGHT|TOP|LEFT),
	  row_(row),
	  col_(col)
	{}
	// 1101 1101
	// 0100 0010
	// 0100 0000
	bool has_wall(Direction dir) const {
		return dir & walls_;
	}
	
	// 0110 0110
	// 1000 0100
	// 1110 0110
	Cell& set_wall(Direction dir) {
		walls_ |= dir;
		return *this;
	}
	
	//  0110 0110 0110
	//  0100 0001 0010
	//~?1011 1110 1101
	//&?0010 0110 0100
	Cell& unset_wall(Direction dir) {
		walls_ &= ~dir;
		return *this;
	}
	static const int WALL_SIZE = 20;
	
	void draw(ostream& out) const {
		out << (col_+1)*WALL_SIZE << ' '
			<< (row_+1)*WALL_SIZE << ' '
			<< "moveto" << endl;
		
		out << 5 << ' ' << 5 << ' '
			<< "rlineto" << endl;
	}
};

class Board {
	unsigned height_, width_;
	vector<Cell> cells_;
public:
	Board(unsigned height, unsigned width)
	: height_(height),
	  width_(width)
	{
		for(unsigned row=0;row<height_;row++) {
			for(unsigned col=0;col<width_;col++) {
				cells_.push_back(Cell(row,col));
			}
		}
	}

	Cell& get_cell(unsigned row, unsigned col) {
		return cells_[row*width_+col];
	}

	const Cell& get_cell(unsigned row, unsigned col) const {
		return cells_[row*width_+col];
	}
	
	void draw(ostream& out) const {
		out << "newpath" << endl;
		for(vector<Cell>::const_iterator it=cells_.begin();
			it!=cells_.end();++it) {
			
			(*it).draw(out);	
		}	
		out << "stroke" << endl;
		out << "showpage" << endl;
	}
};


int main() {
	Board b(20, 20);
	b.draw(cout);

/*
	Cell c(0,0);
	cout << c.has_wall(LEFT) << endl;
	c.unset_wall(LEFT);
	cout << c.has_wall(LEFT) << endl;
	cout << c.has_wall(RIGHT) << endl;
	c.set_wall(LEFT);
	cout << c.has_wall(LEFT) << endl;
	
	Board b(20,20);
	
	Cell& rc=b.get_cell(10,10);
	rc.unset_wall(DOWN);
	cout << "rc.has_wall(down)=" << rc.has_wall(DOWN) << endl;
	cout << b.get_cell(10,10).has_wall(DOWN) << endl;
	
	//const Board& cb=b;
	
	//const Cell& crc=cb.get_cell(10,10);
	//crc.unset_wall(UP);
*/
	return 0;
}



