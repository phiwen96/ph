export module Ph.Concepts.Types;

import Ph.Concepts.Bool;

import std;

namespace ph
{
	export
	{
		template <typename... T>
		struct types_t 
		{
			template <template <typename...> typename U>
			using types = U <T...>;
		};

		template <>
		struct types_t <>
		{

		};
 
		template <typename T>
		concept Types = requires 
		{
			typename T::template types <std::tuple>;
		};
	}
}




using namespace ph;

consteval auto Types_test () noexcept -> Bool auto
{
	static_assert (Types <types_t <int, char>>);
	static_assert (Types <types_t <int>>);
	static_assert (not Types <types_t <>>);
	Bool auto b = true;

	return b;
}


static_assert (Types_test ()); 



