export module Ph.Assert;


namespace ph 
{
	export 
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
}








consteval auto Assert_test () -> bool
{
	using namespace ph;
	
	return true;
}

static_assert (Assert_test ());
