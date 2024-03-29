export module Ph.Number;

export import Ph.Number.Signed;
export import Ph.Number.Unsigned;
export import Ph.Number.Integer;
export import Ph.Number.Float;

export namespace ph 
{
	 
	
	template <typename T>
	concept Number = Signed <T> or Unsigned <T>;
	
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;

consteval auto Number_test () -> bool
{
	using namespace ph;

	constexpr auto assert_number = [] <Number> {};
	constexpr auto assert_not_number = [] <typename T> requires (not Number <T>) {};

	testing::assert_all <int, bool, char, float, double, long double> (assert_number);
	testing::assert_all <char const*, int const (&) [10]> (assert_not_number);

	return true;
}

static_assert (Number_test ());

#endif