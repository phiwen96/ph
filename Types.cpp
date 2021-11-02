export module Ph.Concepts.Types;

import Ph.Concepts.Bool;

namespace ph
{
	export
	{
		template <typename... T>
		struct types_t 
		{
			template <template <typename...> typename U>
			using types = U <T...>;
		};

		template <>
		struct types_t <>
		{

		};

		template <typename T>
		concept Types = requires (T t)
		{
			typename T::template types <types_t>;
		};
	}
}




using namespace ph;

consteval auto test () noexcept -> Bool auto
{
	Bool auto b = true;

	return b;
}


static_assert (test ()); 



