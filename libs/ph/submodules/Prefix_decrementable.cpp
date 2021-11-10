export module Ph.Prefix_decrementable;

import Ph.Reference;

namespace ph 
{
	template <typename T>
	concept Prefix_decrementable = requires (T t) 
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

consteval auto Prefix_decrementable_test () noexcept -> bool
{
	using namespace ph;
	
	constexpr auto assert_Prefix_decrementable = [] <Prefix_decrementable> {};
	constexpr auto assert_not_Prefix_decrementable = [] <typename T> requires (not Prefix_decrementable <T>) {};

	static_assert (Prefix_decrementable <int>);
	static_assert (not Prefix_decrementable <std::vector <int>>);

	return true;
}

static_assert (Prefix_decrementable_test ());

#endif

