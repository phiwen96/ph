import Ph;
import std;
import Darwin;

using std::cout, std::endl;

using namespace ph;


auto main (int, char**) -> int
{ 
	cout << red << "----------" << yellow << endl;

    
	// return 0;

	// Process auto process = spawn ();

	// if (process.has_child ())
	// {
	// 	server (443, "SERVER_ID=048532");

	// } else 
	// {
	// 	// ph::client (443, "CLIENT_ID=057532");
	// }


	File auto f = ph::open ("/Users/philipwenkel/Github/ph/haha.cpp");
	Error auto e = f;
	// assert (not e);
	std::cout << (bool) e << std::endl;
	// f << "hej";
	// cout << f;
	
    

	// assert (not f.get_error ());

	return 0;
}
