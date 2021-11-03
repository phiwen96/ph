export module Ph.Concepts.Types.Type_list;



namespace ph
{
	export 
	{
		template <typename T>
		concept Type_list = requires (T t)
		{
			true;
		};

		template <typename...>
		struct type_list_t;

		template <typename T, typename... U>
		struct type_list_t <T, U...>
		{
			template <template <typename...> typename V>
			using types = V <T, U...>;
		};

		template <>
		struct type_list_t <>
		{
			template <template <typename...> typename U>
			using types = U <>;
		};
	}
}

using namespace ph;

consteval bool Type_list_test ()
{
	static_assert (Type_list <type_list_t <int, char>>);
	static_assert (Type_list <type_list_t <int>>);
	static_assert (Type_list <type_list_t <>>);

	return true;
}

static_assert (Type_list_test ());