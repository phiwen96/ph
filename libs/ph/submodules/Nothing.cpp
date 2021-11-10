export module Ph.Nothing;

import Ph.Same_as;

namespace ph 
{
	template <typename T>
	struct nothing 
	{
		constexpr static bool value = false;
	};

	template <>
	struct nothing <void>
	{
		constexpr static bool value = true;
	};

	export template <typename T>
	concept Nothing = nothing <T>::value;
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;
import std;

consteval auto Nothing_test () noexcept -> bool
{
	using namespace ph;
	static_assert (Nothing <void>);
	static_assert (not Nothing <char*>);
	return true;
}

static_assert (Nothing_test ());

#endif
