export module Ph.Number.Float;

import Ph.Convertible_to;
import Ph.Assert;


namespace ph 
{
	export template <typename T>
	concept Floating = Convertible_to <T, float> or Convertible_to <T, double> or Convertible_to <T, long double>;
}



consteval auto Float_test () -> bool
{
	using namespace ph;

	constexpr auto assert_floating = [] <Floating> {};
	constexpr auto assert_not_floating = [] <typename T> requires (not Floating <T>) {};

	assert_all <int, bool, char, float, double, long double> (assert_floating);
	assert_all <char const*, int const (&) [10]> (assert_not_floating);

	return true;
}

static_assert (Float_test ());