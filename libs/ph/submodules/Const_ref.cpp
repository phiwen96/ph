export module Ph.Const_ref;
import Ph.Const;
import Ph.Reference;

export namespace ph 
{
	template <typename T>
	concept Const_ref = Const <T> and Reference <T>;
}



/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;

consteval auto Const_ref_test () -> bool
{
	using namespace ph;

	constexpr auto assert_const_ref = [] <Const_ref> {};
	constexpr auto assert_not_const_ref = [] <typename T> requires (not Const_ref <T>) {};

	testing::assert_all <int const&> (assert_const_ref);
	testing::assert_all <int&, int&&, int const> (assert_not_const_ref);

	return true;
}

static_assert (Const_ref_test ());


#endif

