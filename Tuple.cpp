export module Ph.Concepts.Tuple;

namespace ph 
{
	export 
	{
		template <typename T>
		concept Tuple = requires (T t)
		{
			true;
		};

		template <typename Head, typename... Tail>
		struct tuple_t 
		{
			using self = tuple_t <Head, Tail...>;

		private:
			Head _head;
			tuple_t <self, Tail...> _tail;
		};

		template <typename... T>
		struct tuple_t <tuple_t <T...>>
		{

		};
	}
}

using namespace ph;

consteval auto Tuple_test () noexcept -> bool 

{
	static_assert (Tuple <tuple_t <int>>);

	

	return true;
}

static_assert (Tuple_test ());