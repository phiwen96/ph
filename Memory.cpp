export module Ph.Concepts.Memory;

export import Ph.Concepts.Memory.Allocator;
export import Ph.Concepts.Memory.Arena;

import Ph.Concepts.Bool;
import Ph.Concepts.Error;
import std;

// auto allocated = size_t{0};
// 		// Overload operator new and delete to track allocations
// void* operator new (size_t size) 
// {
// 	void* p = std::malloc(size);
// 	allocated += size;
// 	return p;
// }

// void operator delete (void* p) noexcept 
// {
// 	return std::free(p);
// } 


namespace ph 
{
	export 
	{
		constexpr auto is_aligned (void* ptr, std::size_t alignment) -> Error auto
		{
			Bool auto result = true;

			Error auto err = error_t <bool> {result};

			err and ptr != nullptr and std::has_single_bit (alignment); 

			auto s = std::numeric_limits<std::size_t>::max();
			auto aligned_ptr = ptr;
			std::align(alignment, 1, aligned_ptr, s);
			result = result and ptr == aligned_ptr;
 
			return (error_t <bool>&&) result;
		}
	}
}

using namespace ph;

consteval auto Memory_test () -> Bool auto 
{

	return true;
}

static_assert (Memory_test ());
