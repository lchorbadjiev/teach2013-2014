#include <iostream>
#include <vector>
using namespace std;

enum Direction {
	NONE = 0,
	UP = 1,
	LEFT = 1 << 1,
	DOWN = 1 << 2,
	RIGHT = 1 << 3
};


class Cell {
	unsigned int walls_;
	unsigned int row_;
	unsigned int col_;
public:
	Cell(unsigned int row, unsigned int col,
		unsigned int walls=UP|LEFT|DOWN|RIGHT)
	: walls_(walls),
	  row_(row),
	  col_(col)
	{}
	
	bool has_wall(Direction dir) const {
		return dir & walls_;
	}

	Cell& set_wall(Direction dir) {
		walls_ |= dir;	
		return *this;
	}
	
	Cell& unset_wall(Direction dir) {
		walls_ &= ~dir;
		return *this;
	}

	unsigned get_row() const {
		return row_;
	}
	
	unsigned get_col() const {
		return col_;
	}
};

class BoardError{};

class Board {
	unsigned width_;
	unsigned height_;
	vector<Cell> cells_;
public:
	Board(unsigned width, unsigned height)
	: width_(width),
	  height_(height)
	{
		for(unsigned row=0;row<height_;row++) {
			for(unsigned col=0;col<width_;col++) {
				cells_.push_back(Cell(row,col));
			}
		}
	}
	const Cell& get_cell(unsigned row, unsigned col) const {
		return cells_[row*width_+col];
	}
	
	Cell& get_cell(unsigned row, unsigned col) {
		return cells_[row*width_+col];
	}	
};



int main() {
	Cell c1(0,0);
	cout << c1.has_wall(UP) << ' ' << c1.has_wall(DOWN) << endl;
	c1.unset_wall(UP);
	cout << c1.has_wall(UP) << ' ' << c1.has_wall(DOWN) << endl;
	c1.unset_wall(DOWN);
	cout << c1.has_wall(UP) << ' ' << c1.has_wall(DOWN) << endl;
	c1.set_wall(UP).set_wall(DOWN);
	cout << c1.has_wall(UP) << ' ' << c1.has_wall(DOWN) << endl;
	
	Board b(20,20);
	Cell c13=b.get_cell(1,3);
	cout << c13.get_row() << ' ' << c13.get_col() << endl;
	
	
	b.get_cell(1,3).unset_wall(UP);
	b.get_cell(0,3).unset_wall(DOWN);
	cout << b.get_cell(1,3).has_wall(UP) << endl;
	cout << b.get_cell(0,3).has_wall(DOWN) << endl;
	
	return 0;
}






