import Ph;
import std;
import Darwin;

auto operator new(size_t size) -> void* {
 void* p = std::malloc(size);
 std::cout << "allocated " << size << " byte(s)\n";
 return p;
}

auto operator delete(void* p) noexcept -> void {
	std::cout << "deleted memory\n";
 return std::free(p);
}

auto operator new[](size_t size) -> void* {
 void* p = std::malloc(size);
 std::cout << "allocated " << size << " byte(s) with new[]\n";
 return p;
}

auto operator delete[](void* p) noexcept -> void {
 std::cout << "deleted memory with delete[]\n";
 return std::free(p);
}

using namespace ph;





auto main (int i, char** s) -> int
{ 
	// Arguments auto args = parse_args (s, i);
	
	return 0;
}
