export module Ph.Size;

import Ph.Convertible_to;
import std;

export namespace ph 
{
	template <typename T>
	concept Size = Convertible_to <T, std::size_t>;
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;

consteval auto Size_test () -> bool
{
	using namespace ph;

	constexpr auto assert_signed = [] <Size> {};
	constexpr auto assert_not_signed = [] <typename T> requires (not Size <T>) {};
	
	return true;
}

static_assert (Size_test ());

#endif