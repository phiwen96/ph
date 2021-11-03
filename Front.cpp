export module Ph.Concepts.Types.List.Front;

namespace ph
{
	export 
	{
		template <typename>
		struct front_t;

		template <template <typename...> typename T, typename U, typename... V>
		struct front_t <T <U, V...>>
		{
			using type = U;
		};

		template <typename T>
		concept Front = requires ()
		{
			true;
		};
	}
}



using namespace ph;


consteval auto Front_test () noexcept -> bool
{
	return true;
}


static_assert (Front_test ()); 
