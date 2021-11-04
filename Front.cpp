export module Ph.Concepts.Types.List.Front;

import Ph.Concepts.Same_as;
import Ph.Assert;

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
struct tp {}; // typelist

consteval auto Front_test () noexcept -> bool
{
	using namespace type;

	constexpr auto assert_front = [] <Front> {};

	assert_all <tp <int, char>, tp <char>> (assert_front);


	static_assert (type::Front <tp <int, char>>);
	static_assert (type::Front <tp <char>>);
	static_assert (not type::Front <tp <>>);
	static_assert (Same_as <type::front <tp <int, char>>, int>);
	return true;
}


static_assert (Front_test ()); 
