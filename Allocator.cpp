export module Ph.Concepts.Memory.Allocator;

import Ph.Concepts.Bool;
import Ph.Concepts.Memory.Arena;


namespace ph 
{
	export 
	{
		template <typename A>
		concept Allocator = requires (A a)
		{
			true;
		};

		struct allocator_t 
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