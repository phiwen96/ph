import Ph;
import std;
import Darwin;

using std::cout, std::endl;



auto main (int, char**) -> int
{ 
	cout << ph::red << "----------" << ph::yellow << endl;

    
	// return 0;

	ph::Process auto process = ph::spawn ();

	if (process.has_child ())
	{
		ph::server (443, "SERVER_ID=048532");

	} else 
	{
		// ph::client (443, "CLIENT_ID=057532");
	}

	
    
	return 0;
}
