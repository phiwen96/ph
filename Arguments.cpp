export module Ph.Build.Arguments;

import Ph.Concepts.Strings;

namespace ph 
{
	export 
	{
		template <typename A>
		concept Arguments = Strings <A>;

		constexpr auto parse_args (Strings auto&& args) noexcept -> Arguments auto
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