export module Ph.Const;

export namespace ph 
{
	template <typename T>
	concept Const = not requires (T t0, T t1)
	{
		t0 = t1;
	};
}



/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;

consteval auto Const_test () -> bool
{
	using namespace ph;

	constexpr auto assert_const = [] <Const> {};
	constexpr auto assert_not_const = [] <typename T> requires (not Const <T>) {};

	testing::assert_all <int const, int const&> (assert_const);
	// testing::assert_all <int, int const, int*, int const*, int**> (assert_not_const);

	return true;
}

static_assert (Const_test ());

#endif

