import Ph;
import std;
import Darwin;

using std::cout, std::endl;

using namespace ph;


auto main (int, char**) -> int
{ 
	cout << red << "----------" << yellow << endl;

	auto vec = std::vector{1, 1, 0, 1, 1, 0, 0, 1};
	// std::cout << std::ranges::count(vec, 0); // Prints 3
	
    Vector auto v1 = ph::vector <int, 3, 100> {0, 1, 2};


	// value = value and (v1 == v1);

	Vector auto v2 = ph::vector <int, 2, 100> {0, 3};
	Bool auto b = v2 | contains (4);
	for (auto i : v2)
	{
		cout << i << endl;
	}

	return 0;
}
