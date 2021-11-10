export module Ph.Postfix_decrementable;

import Ph.Reference;

namespace ph 
{
	template <typename T>
	concept Postfix_decrementable = requires (T t) 
	{
		t--;
	};

	export template <Postfix_decrementable T>
	constexpr auto decrement (T && i) noexcept -> T& 
	{
		return i--;
	}
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;
import std;

consteval auto Postfix_decrementable_test () noexcept -> bool
{
	using namespace ph;
	
	constexpr auto assert_Postfix_decrementable = [] <Postfix_decrementable> {};
	constexpr auto assert_not_Postfix_decrementable = [] <typename T> requires (not Postfix_decrementable <T>) {};

	static_assert (Postfix_decrementable <int>);
	static_assert (not Postfix_decrementable <std::vector <int>>);

	return true;
}

static_assert (Postfix_decrementable_test ());

#endif

