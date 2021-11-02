export module Ph.Debug;

namespace ph 
{
	export 
	{
		template <typename D>
		concept Debug = requires (D d)
		{
			true;
		};
	}
}

using namespace ph;

consteval auto test () -> bool
{

	return true;
}

static_assert (test ());