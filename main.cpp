import Ph;
import std;
import Darwin;

using std::cout, std::endl;

using namespace ph;


auto main (int, char**) -> int
{ 
	cout << red << "----------" << yellow << endl;

  
	
    Vector auto v1 = ph::vector <int, 3, 100> {0, 1, 2};


	// value = value and (v1 == v1);

	Vector auto v2 = ph::vector <int, 2, 100> {0, 3};

	for (auto i : v2)
	{
		cout << i << endl;
	}

	return 0;
}
