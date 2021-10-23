import <iostream>;
import <vector>;



import concepts;

int main()
{
    std::cout << "Hello, World!\n";
	fitta ();
	com ();
	circ ();

	return 0;
}


// clang++ -Wall -std=c++2a -fmodules -c ph.cpp -Xclang -emit-module-interface -o ph.pcm && clang++ -Wall -std=c++2a -fimplicit-modules -fimplicit-module-maps -fprebuilt-module-path=. main.cpp ph.pcm -o main && ./main