export module Ph.Concepts.Types.List.Front;

import Ph.Concepts.Same_as;

namespace ph::type
{
		template <typename>
		struct front_t;

		template <template <typename...> typename T, typename U, typename... V>
		struct front_t <T <U, V...>>
		{
			using type = U;
		};


	export 
	{
		template <typename T>
		concept Front = requires ()
		{
			typename front_t <T>::type;
		};

		template <Front F>
		using front = typename front_t <F>::type;
	}
}



using namespace ph;

template <typename...>
struct _tp {};

consteval auto Front_test () noexcept -> bool
{
	static_assert (type::Front <_tp <int, char>>);
	static_assert (type::Front <_tp <char>>);
	static_assert (not type::Front <_tp <>>);
	static_assert (Same_as <type::front <_tp <int, char>>, int>);
	return true;
}


static_assert (Front_test ()); 
