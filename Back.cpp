export module Ph.Concepts.Types.List.Back;

import Ph.Concepts.Same_as;

namespace ph::type
{
		template <typename>
		struct back_t;

		template <template <typename...> typename T, typename U, typename... V>
		struct back_t <T <U, V...>>
		{
			using type = typename back_t <T <V...>>::type;
		};

		template <template <typename...> typename T, typename U>	
		struct back_t <T <U>>
		{
			using type = U;
		};


	export 
	{
		template <typename T>
		concept Back = requires ()
		{
			typename back_t <T>::type;
		};

		template <Back B>
		using back = typename back_t <B>::type;
	}
}



using namespace ph;

template <typename...>
struct _tp {};

consteval auto Back_test () noexcept -> bool
{
	static_assert (type::Back <_tp <int, char>>);
	static_assert (type::Back <_tp <char>>);
	static_assert (not type::Back <_tp <>>);
	static_assert (Same_as <type::back <_tp <int, char>>, char>);
	return true;
}


static_assert (Back_test ()); 
