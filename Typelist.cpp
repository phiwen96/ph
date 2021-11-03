export module Ph.Concepts.Types.Typelist;



namespace ph
{
	export 
	{

		

		template <typename T>
		concept Typelist = requires (T t)
		{
			typename T::tail;
			typename T::front;
			typename T::back;
		};

		template <typename...>
		struct typelist_t;

		template <typename T, typename... U>
		struct typelist_t <T, U...>
		{
			template <template <typename...> typename V>
			using types = V <T, U...>;
		};

		template <>
		struct typelist_t <>
		{
			template <template <typename...> typename U>
			using types = U <>;
		};
	}
}

using namespace ph;

consteval bool Typelist_test ()
{
	// static_assert (Typelist <Typelist_t <int, char>>);
	// static_assert (Typelist <Typelist_t <int>>);
	// static_assert (Typelist <Typelist_t <>>);

	return true;
}

static_assert (Typelist_test ());