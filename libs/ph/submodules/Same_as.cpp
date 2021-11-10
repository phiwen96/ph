
export module Ph.Same_as;

namespace ph 
{

	template <typename T, typename U>
	struct same 
	{
		constexpr static bool value = false;
	};

	template <typename T>
	struct same <T, T>
	{
		constexpr static bool value = true;
	};


	export template <typename T, typename U>
	concept Same_as = same <T, U>::value;

}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;
import std;

consteval auto Same_as_test () noexcept -> bool
{
	using namespace ph;
	static_assert (Same_as <char*, char*>);
	return true;
}

static_assert (Same_as_test ());

#endif

