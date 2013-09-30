namespace elsys {
	class Student {
	
	
	};


	class Teacher {
	
	};

};

namespace tu {
	class Student {
	
	};
	
	
	
};

//using namespace elsys;
//using namespace tu;

using elsys::Teacher;

int main() {
	elsys::Student st;
	tu::Student st2;
	
	Teacher t;

	return 0;
}


