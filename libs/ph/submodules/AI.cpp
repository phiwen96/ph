export module Ph.AI;

namespace ph 
{
	template <typename T>
	concept AI = requires (T t) 
	{
		--t;
	};
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;
import std;

consteval auto AI_test () noexcept -> bool
{
	using namespace ph;
	constexpr auto assert_AI = [] <AI> {};
	constexpr auto assert_not_AI = [] <typename T> requires (not AI <T>) {};


	return true;
}

static_assert (AI_test ());

#endif

