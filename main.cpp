import Ph;
import std;
import Darwin;

using std::cout, std::endl;

using namespace ph;


auto main (int, char**) -> int
{ 
	cout << red << "----------" << yellow << endl;

  
	
    String auto s = append ("hej ", "då", " :)");
	free (s);

	return 0;
}
