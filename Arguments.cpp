export module Ph.Build.Arguments;

namespace ph 
{
	export 
	{
		template <typename A>
		concept Arguments = requires (A a)
		{
			true;
		};
	}
}

using namespace ph;

consteval auto Arguments_test () noexcept -> bool 
{

	return true;
}

static_assert (Arguments_test ());