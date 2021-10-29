import Ph;


import std;

using std::cout, std::endl;

auto fun (int) {}

int main (int, char**)
{ 
	cout << red << "----------" << yellow << endl;

    auto lambda = [] (Process auto& p)
	{
		cout << "hello world" << endl; 
		p.set_done (true);
		
		return 0;
	};

	Process auto process = spawn (lambda);
    cout << process.done () << endl;
	return 0;
}
