export module Ph.Prefix_incrementable;

import Ph.Reference;

namespace ph 
{
	export template <typename T>
	concept Prefix_incrementable = requires (T t) 
	{
		++t;
	};

	export template <Prefix_incrementable T>
	constexpr auto increment (T && i) noexcept -> T& 
	{
		return ++i;
	}
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;
import std;

consteval auto Prefix_incrementable_test () noexcept -> bool
{
	using namespace ph;
	
	constexpr auto assert_Prefix_incrementable = [] <Prefix_incrementable> {};
	constexpr auto assert_not_Prefix_incrementable = [] <typename T> requires (not Prefix_incrementable <T>) {};

	static_assert (Prefix_incrementable <int>);
	static_assert (not Prefix_incrementable <std::vector <int>>);

	return true;
}

static_assert (Prefix_incrementable_test ());

#endif

