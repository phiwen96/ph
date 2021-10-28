import Ph;


import std;

using std::cout, std::endl;

auto fun (int) {}

int main (int, char**)
{ 
	cout << red << "----------" << yellow << endl;
    auto lambda = []{cout << "hello world" << endl; return 0;};
	Process auto process = spawn (lambda);
    cout << "yj" << endl;
	return 0;
}
