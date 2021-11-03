export module Ph.Build.Arguments;

import Ph.Concepts.String;
import Ph.Concepts.Strings;

namespace ph 
{
	export 
	{
		template <typename A>
		concept Arguments = requires (A a)
		{
			true;
		};

		auto parse_args ()
		{
			
		}
	}
}

using namespace ph;

consteval auto Arguments_test () noexcept -> bool 
{

	return true;
}

static_assert (Arguments_test ());