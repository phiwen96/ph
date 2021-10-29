import Ph;


import std;

using std::cout, std::endl;

auto fun (int) {}

int main (int, char**)
{ 
	cout << red << "----------" << yellow << endl;

    auto work = [] (Process auto& p)
	{
		cout << "hello world" << endl; 
		p.set_done (true);
		
		return 0;
	};

	Process auto process = spawn_and_work (work);

	Signal auto s = sig <SIGUSR1> 
	{
		[] (int) {};
	};

    
	return 0;
}
