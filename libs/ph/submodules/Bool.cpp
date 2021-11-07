export module Ph.Bool;

import Ph.Convertible_to;
import Ph.Assert;

export namespace ph 
{
	template <typename T>
	concept Bool = Convertible_to <T, bool>;
}






/*==================================
 TESTING
====================================*/
#ifdef Testing

consteval bool Bool_test ()
{
	using namespace ph;

	constexpr auto assert_bool = [] <Bool> {};
	constexpr auto assert_not_bool = [] <typename T> () requires (not Bool <T>) {};

	struct A {};
	struct B {operator bool (){return true;}};

	assert_all <bool, B> (assert_bool);
	assert_all <A> (assert_not_bool);

	return true;
}

static_assert (Bool_test ());

#endif