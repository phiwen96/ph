export module Ph.Concepts.Types.List;

import Ph.Concepts.Same_as;

export import Ph.Concepts.Types.List.Front;
export import Ph.Concepts.Types.List.Back;
export import Ph.Concepts.Types.List.Transform;

namespace ph
{
	// template <typename...>
	// struct back_type_t;

	// template <template <typename...> typename T, typename U, typename... V>
	// struct back_type_t <T <U, V...>>
	// {
	// 	using type = typename back_type_t <U...>::type;
	// };

	// template <typename T>
	// struct back_type_t <T>
	// {
	// 	using type = T;
	// };
	export 
	{
		template <typename...>
		struct typelist_t
		{

		};
	}




	export 
	{

		

		template <typename T>
		concept Typelist = requires ()
		{
			true;
			// typename back_type_t <T>::type;
		};

		

	}
}

using namespace ph;

consteval bool Typelist_test ()
{
	static_assert (Typelist <typelist_t <int, char>>);
	// static_assert (Same_as <typename front_t <typelist_t <int, char>>::type, int>);
	// static_assert (Typelist <Typelist_t <int>>);
	// static_assert (Typelist <Typelist_t <>>);

	return true;
}

static_assert (Typelist_test ());