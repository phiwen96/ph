export module Ph.Assert;

import Ph.Concepts.Bool;
import Ph.Concepts.Void;
import Ph.Concepts.Same_as;
import Ph.Concepts.True;

namespace ph 
{
	template <auto boolfunction, typename...>
	struct assert_all_t;

	template <auto boolfunction, typename T, typename... U>
	struct assert_all_t <boolfunction, T, U...>
	{
		constexpr static bool value = boolfunction.template operator () <T> () and assert_all_t <boolfunction, U...>::value;
	};

	template <auto boolfunction, typename T>
	struct assert_all_t <boolfunction, T>
	{
		constexpr static bool value = boolfunction.template operator () <T> ();
	};

	constexpr auto _assert_true = [] (Bool auto&& b) constexpr noexcept -> Bool auto
	{
		return b == true;
	};

	export 
	{
		
		consteval auto assert_true (Bool auto&&... b)
		requires requires ()
		{
			requires ((b == true) and ...);
		}
		{

		}
		
		
		template <typename T>
		consteval inline auto assert_all (auto&& lambda) noexcept -> Void auto 
		requires requires ()
		{
			lambda.template operator () <T> ();
		}
		{
			// static_assert (assert_all_t <boolfunction, T>::value);
		}


	}
}


using namespace ph;

consteval auto Assert_test () -> Bool auto
{
	// assert_true (true, true, true);

	constexpr auto is_bool = [] <Bool> () constexpr noexcept {};
	// assert_all <int> (string_check); 
	assert_all <bool> (is_bool);
	// assert_all <string_check, int> ();
	// assert_all <int> ([] <typename T> {return Same_as <char, T>;});
	return true;
}


static_assert (Assert_test ());