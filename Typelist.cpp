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



	template <typename>
	struct front_t;

	template <template <typename...> typename T, typename U, typename... V>
	struct front_t <T <U, V...>>
	{
		using type = U;
	};

	static_assert (Same_as <typename front_t <typelist_t <int, char>>::type, int>);



	template <typename>
	struct pop_front_t;

		template <template <typename...> typename T, typename U, typename... V>
	struct pop_front_t <T <U, V...>>
	{
		using type = T <V...>;
	} ;

	static_assert (Same_as <typename pop_front_t <typelist_t <int, char>>::type, typelist_t <char>>);


	export 
	{

		

		template <typename T>
		concept Typelist = requires ()
		{
			typename front_t <T>::type;
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