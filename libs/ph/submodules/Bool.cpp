export module Ph.Bool;

import Ph.Convertible_to;

export namespace ph 
{
	template <typename T>
	concept Bool = Convertible_to <T, bool>;
}






/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;

consteval bool Bool_test ()
{
	using namespace ph;

	constexpr auto assert_bool = [] <Bool> {};
	constexpr auto assert_not_bool = [] <typename T> () requires (not Bool <T>) {};

	struct A {};
	struct B {operator bool (){return true;}};

	testing::assert_all <bool, B> (assert_bool);
	testing::assert_all <A> (assert_not_bool);

	return true;
}

static_assert (Bool_test ());

#endif