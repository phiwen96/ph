export module Ph.Convertible_to;

export namespace ph 
{

	template <typename T, typename U>
	concept Convertible_to = requires (T t, U u)
	{
		u = t;
	};
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

using namespace ph;

import Ph.Test;


consteval auto Convertible_to_test () -> bool
{
	

	constexpr auto assert_convertible_to = [] <Convertible_to <int>> {};
	constexpr auto assert_not_convertible_to = [] <typename T> requires (not Convertible_to <T, int>) {};
	

	return true;
}

static_assert (Convertible_to_test ());

#endif