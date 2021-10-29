import Ph;


import std;
import Darwin;

using std::cout, std::endl;

auto fun (int) {}

int main (int, char**)
{ 
	cout << red << "----------" << yellow << endl;

    

	Signal auto s = sig <SIGUSR1> 
	{
		[] (int) 
		{
			cout << "yoyoyo" << endl;
		}
	};

	auto work = [] (Process auto& p)
	{
		cout << "hello world" << endl; 
		p.set_done (true);
		raise (SIGUSR1);
		
		return 0;
	};

	Process auto p = spawn_and_work (work);

	

	assert (p.get_error () == false);

	

	


	
    
	return 0;
}
