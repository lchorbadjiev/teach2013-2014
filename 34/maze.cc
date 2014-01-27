#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

enum Direction {
	NONE = 0,
	DOWN = 1,    // 0001
	RIGHT = 1<<1,// 0010
	UP = 1<<2,  // 0100
	LEFT = 1<<3  // 1000
// 0001
// 1111
// 1010
};

class Cell {
	unsigned walls_;
	unsigned row_;
	unsigned col_;
	bool visited_;
public:

	Cell(int row, int col)
	: walls_(DOWN|RIGHT|UP|LEFT),
	  row_(row),
	  col_(col),
	  visited_(false)
	{}
	
	
	int get_row() const {
		return row_;
	}
	int get_col() const {
		return col_;
	}
	bool is_visited() const {
		return visited_;
	}
	Cell& visit() {
		visited_=true;
		return *this;
	}
	
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
	
	string draw_wall(bool has_wall) const {
		return (has_wall?" rlineto":" rmoveto");
	}
	
	void draw(ostream& out) const {
		
		out << (col_+1)*WALL_SIZE << ' '
			<< (row_+1)*WALL_SIZE << ' '
			<< "moveto" << endl;
		
		out << WALL_SIZE << ' ' << 0 
			<< draw_wall(has_wall(DOWN)) << endl;
		out << 0 << ' ' << WALL_SIZE 
			<< draw_wall(has_wall(RIGHT)) << endl;
		out << -WALL_SIZE << ' ' << 0
			<< draw_wall(has_wall(UP)) << endl;
		out << 0 << ' ' << -WALL_SIZE 
			<< draw_wall(has_wall(LEFT)) << endl;	
	}
};

class BoardError{};

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
	
	bool has_neighbour(int row, int col, 
						Direction dir) const {
		if(row == 0 and dir==DOWN) {
			return false;
		}
		if(row==(height_-1) and dir==UP) {
			return false;
		}
		if(col==0 and dir==LEFT) {
			return false;
		}
		if(col==(width_-1) and dir==RIGHT) {
			return false;
		}
		return true;
	}
	
	Cell& get_neighbour(int row, int col, Direction dir) {
		if(!has_neighbour(row,col,dir)) {
			throw BoardError();
		}
		int nr=row+((dir==UP)? +1:( (dir==DOWN)?-1: 0));
		int nc=col+((dir==RIGHT)?+1:((dir==LEFT)?-1:0));
		
		return get_cell(nr,nc);
	}
	
	void drill_wall(int row, int col, Direction dir) {
		Cell& c=get_cell(row, col);
		c.unset_wall(dir);
		if(!has_neighbour(row,col,dir)) {
			return;
		}
		Cell& n=get_neighbour(row, col, dir);
		switch(dir) {
		case UP:
			n.unset_wall(DOWN);
			break;
		case DOWN:
			n.unset_wall(UP);
			break;
		case RIGHT:
			n.unset_wall(LEFT);
			break;
		case LEFT:
			n.unset_wall(RIGHT);
			break;
		default:
			throw BoardError();
		}
	}
	
	const static Direction DIRS[];
	const static int DSIZE=4;
	
	Direction has_unvisited_neighbour(int row, int col) {
		for(int i=0;i<DSIZE;i++) {
			Direction dir=DIRS[i];
			if(has_neighbour(row,col,dir)) {
				Cell& n=get_neighbour(row,col,dir);
				if(!n.is_visited()) {
					return dir;
				}
			}
		}
		return NONE;
	}
	
	Direction get_random_unvisited_neighbour(int row, int col) {
		if(has_unvisited_neighbour(row,col)==NONE) {
			return NONE;
		}
		
		while(true) {
			int ind=rand()%DSIZE;
			Direction dir=DIRS[ind];
			
			if(has_neighbour(row,col,dir)) {
				Cell& c= get_neighbour(row,col,dir);
				if(!c.is_visited()) {
					return dir;
				}
			}		
		}
	}
	
	void generate(int row, int col) {
		Cell& c=get_cell(row,col);
		c.visit();
		while(true) {
			if(has_unvisited_neighbour(row,col)==NONE) {
				return;
			}
			Direction dir
				=get_random_unvisited_neighbour(row,col);
			drill_wall(row,col,dir);
			Cell& n=get_neighbour(row,col,dir);
			generate(n.get_row(),n.get_col());
		}
	}
	
};
const Direction Board::DIRS[] = {UP,LEFT,DOWN,RIGHT};

int main() {
	Board b(20, 20);
	
	b.generate(0,0);
		
	b.draw(cout);

	
	return 0;
}



