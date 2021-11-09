export module Ph.Test.Assert;


export namespace testing
{
	template <typename... T>
	consteval inline auto assert_all (auto&& lambda) noexcept -> void
	requires requires ()
	{
		((lambda.template operator () <T> ()), ...);
	}
	{

	}
		
	template <typename... T>
	consteval inline auto assert_all (auto&& lambda, auto&&... lambdas) noexcept -> void 
	requires requires ()
	{
		((lambda.template operator () <T> ()), ...);
		assert_all <T...> (lambdas...);
	}
	{

	}
}



/*==================================
 TESTING
====================================*/
#ifdef Testing

#endif






inline consteval auto Assert_test () -> bool
{
	
	return true;
}

static_assert (Assert_test ());
