export module Ph.Convertible_to;

import Ph.Assert;


namespace ph 
{

	export template <typename T, typename U>
	concept Convertible_to = requires (T t, U u)
	{
		u = t;
	};


// module :private;

// not valid if there could be a loss of data
static_assert (Convertible_to <long, int>);

static_assert (Convertible_to <short, int>);
static_assert (Convertible_to <short, short>);

}


consteval auto Convertible_to_test () -> bool
{
	using namespace ph;

	constexpr auto assert_convertible_to = [] <Convertible_to <int>> {};
	constexpr auto assert_not_convertible_to = [] <typename T> requires (not Convertible_to <T, int>) {};

	return true;
}

static_assert (Convertible_to_test ());
