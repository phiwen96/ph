export module Ph.Concepts.Memory.Allocator;

import Ph.Concepts.Bool;
import Ph.Concepts.Memory.Arena;

// auto* memory = std::malloc(sizeof(User));
// auto* user = ::new (memory) User("john");
// user->~User();
// std::free(memory);

namespace ph 
{
	export 
	{
		template <typename A>
		concept Allocator = requires (A a)
		{
			true;
		};

		template <typename T>
		struct allocator
		{
			
		};
	}
}

using namespace ph;

consteval auto Allocator_test () noexcept -> Bool auto 
{
	


	return true;
}

static_assert (Allocator_test ());