export module Ph.Concepts.Types;

import Ph.Concepts.Bool;

namespace ph
{
	export
	{
		

		template <typename T>
		concept Types = requires (T t)
		{
			true;
		};
	}
}




using namespace ph;

consteval auto test () noexcept -> Bool auto
{
	Bool auto b = true;

	return b;
}


static_assert (test ()); 



