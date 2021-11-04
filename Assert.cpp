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
		
		
		template <auto boolfunction, typename T>
		consteval inline auto assert_all () noexcept -> Void auto 
		requires requires ()
		{
			requires assert_all_t <boolfunction, T>::value == true;
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

	constexpr auto string_check = [] <typename T> () constexpr noexcept {return Same_as <char, T>;};
	// assert_all <int> (string_check); 
	auto i = assert_all_t <string_check, int>::value;
	// assert_all <string_check, int> ();
	// assert_all <int> ([] <typename T> {return Same_as <char, T>;});
	return true;
}


static_assert (Assert_test ());