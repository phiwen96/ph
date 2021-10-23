import concepts;
// import concepts.Number;

int main()
{
	Number auto a = 10;
	Signed auto b = 2;
	// fitta ();
	// com ();
	// circ ();

	return 0;
}


// clang++ -Wall -std=c++2a -fmodules -c ph.cpp -Xclang -emit-module-interface -o ph.pcm && clang++ -Wall -std=c++2a -fimplicit-modules -fimplicit-module-maps -fprebuilt-module-path=. main.cpp ph.pcm -o main && ./main