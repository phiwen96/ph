export module Ph.Postfix_incrementable;

import Ph.Reference;

namespace ph 
{
	export template <typename T>
	concept Postfix_incrementable = requires (T t) 
	{
		t++;
	};
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;
import std;

consteval auto Postfix_incrementable_test () noexcept -> bool
{
	using namespace ph;
	
	constexpr auto assert_Postfix_incrementable = [] <Postfix_incrementable> {};
	constexpr auto assert_not_Postfix_incrementable = [] <typename T> requires (not Postfix_incrementable <T>) {};

	static_assert (Postfix_incrementable <int>);
	static_assert (not Postfix_incrementable <std::vector <int>>);

	return true;
}

static_assert (Postfix_incrementable_test ());

#endif

