
#ifndef CATCH_TESTING_ON
#include <barrier>
using namespace std;

int main( int argc, char* argv[] ) {
	cout << "hi" << endl;

 
    return 0;
}










#else









#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>

int main( int argc, char* argv[] ) {
 

 
    int result = Catch::Session().run( argc, argv );
    return result;
}
#endif








