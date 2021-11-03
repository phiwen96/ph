export module Ph.Concepts.Strings;

import Ph.Concepts.String;


namespace ph 
{
	export 
	{
		template <typename S>
		concept Strings = requires () 
		{
			true;
		};
	}
}

using namespace ph;

consteval auto Strings_test () -> bool 
{

	return true;
}


static_assert (Strings_test ());