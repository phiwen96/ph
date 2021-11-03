export module Ph.Concepts.Types.Typelist;

import Ph.Concepts.Same_as;

namespace ph
{
	template <typename...>
	struct back_type_t;

	template <typename T, typename... U>
	struct back_type_t <T, U...>
	{
		using type = typename back_type_t <U...>::type;
	};

	template <typename T>
	struct back_type_t <T>
	{
		using type = T;
	};




	template <typename...>
	struct front_type_t;

	template <typename T, typename... U>
	struct front_type_t <T, U...>
	{
		using type = T;
	};




	export 
	{

		

		template <typename T>
		concept Typelist = requires ()
		{
			typename front_type_t <T>::type;
			typename back_type_t <T>::type;
		};

		template <typename...>
		struct typelist_t
		{

		};

	}
}

using namespace ph;

consteval bool Typelist_test ()
{
	static_assert (Typelist <typelist_t <int, char>>);
	// static_assert (Typelist <Typelist_t <int>>);
	// static_assert (Typelist <Typelist_t <>>);

	return true;
}

static_assert (Typelist_test ());