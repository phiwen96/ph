export module Ph.Concepts.Types;

import Ph.Concepts.Bool;

import std;

namespace ph
{
	export
	{


		template <typename T>
		concept Types = requires 
		{
			typename T::template types <std::tuple>;
		};


		template <typename...>
		struct types_t;

		template <typename T, typename... U>
		struct types_t <T, U...>
		{
			template <template <typename...> typename V>
			using types = V <T, U...>;
		};

		template <>
		struct types_t <>
		{
			template <template <typename...> typename U>
			using types = U <>;
		};

		// template <typename... T>
		// requires requires ()
		// {
		// 	types_t <T...> {};
		// }
		// using types = types_t <T...>;
	}
}



using namespace ph;


consteval auto Types_test () noexcept -> Bool auto
{
	static_assert (Types <types_t <int, char>>);
	static_assert (Types <types_t <int>>);
	static_assert (Types <types_t <>>);

	// Types auto t1 = types <int, char> {};



	return true;
}


static_assert (Types_test ()); 



