import Ph;


import std;

using std::cout, std::endl;

auto fun (int) {}

int main (int, char**)
{ 
	cout << red << "----------" << yellow << endl;
	cout << spawn ([]{cout << "hello world" << endl; return 0;}) << endl;
	return 0;
}
