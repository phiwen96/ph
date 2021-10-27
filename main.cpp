import Ph;


import std;

using std::cout, std::endl;

auto fun (int) {}

int main (int, char**)
{ 
	cout << std::is_function_v <decltype (fun)> << endl;
	cout << red << "----------" << yellow << endl;
	cout << "mlkm" << endl;
	return 0;
}
