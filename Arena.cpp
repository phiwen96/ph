export module Ph.Concepts.Memory.Arena;

import Ph.Concepts.Bool;


namespace ph 
{
	export 
	{
		template <typename A>
		concept Arena = requires (A a)
		{
			true;
		};

		struct Arena_t 
		{

		};
	}
}


using namespace ph;

consteval auto Arena_test () noexcept -> Bool auto 
{
	


	return true;
}

static_assert (Arena_test ());