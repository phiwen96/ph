export module Ph.Test;

export import Ph.Assert;



export namespace ph 
{
	 
	
	template <typename T>
	concept Test = true;
	
}






/*==================================
 TESTING
====================================*/
#ifdef Testing

consteval auto Test_test () -> bool
{
	using namespace ph;

	constexpr auto assert_Test = [] <Test> {};
	constexpr auto assert_not_Test = [] <typename T> requires (not Test <T>) {};

	assert_all <int, bool, char, float, double, long double> (assert_Test);
	// assert_all <char const*, int const (&) [10]> (assert_not_Test);

	return true;
}

static_assert (Test_test ());

#endif