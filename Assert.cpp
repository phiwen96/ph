export module Ph.Assert;

import Ph.Concepts.Bool;

namespace ph 
{
	template <auto Boolfunction, typename...>
	struct assert_all_t;

	template <auto Boolfunction, typename T, typename... U>
	requires requires ()
	{
		{Boolfunction.template operator () <T> ()} -> Bool;
	}
	struct assert_all_t <Boolfunction, T, U...>
	{
		constexpr static bool value = Boolfunction <T>::value and assert_all_t <Boolfunction, U...>::value;
	};

	template <auto Boolfunction>
	struct assert_all_t <Boolfunction>
	{
		constexpr static bool value = true;
	};

	export 
	{
		
	}
}