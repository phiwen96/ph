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

	Bool auto ex = ph::exists ("/Users/philipwenkel/Github/ph/haha.cpp");

	File auto f = ph::file {"/Users/philipwenkel/Github/ph/haha.cpp"};
    
	// assert (not f.get_error ());

	return 0;
}
