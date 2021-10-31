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
	cout << ph::error (f) << endl;
	// f << "hej";
	cout << f;
	cout << "hi" << endl;
    

	// assert (not f.get_error ());

	return 0;
}
