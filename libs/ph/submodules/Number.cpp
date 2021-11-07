export module Ph.Number;

export import Ph.Number.Signed;
export import Ph.Number.Unsigned;
export import Ph.Number.Integer;
export import Ph.Number.Float;

import Ph.Assert;


namespace ph 
{
	export 
	{
		template <typename T>
		concept Number = Signed <T> or Unsigned <T>;
	}
}



consteval auto Number_test () -> bool
{
	using namespace ph;

	constexpr auto assert_number = [] <Number> {};
	constexpr auto assert_not_number = [] <typename T> requires (not Number <T>) {};

	assert_all <int, bool, char, float, double, long double> (assert_number);
	assert_all <char const*, int const (&) [10]> (assert_not_number);

	return true;
}

static_assert (Number_test ());