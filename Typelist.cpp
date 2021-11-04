export module Ph.Concepts.Types.List;

import Ph.Concepts.Same_as;

export import Ph.Concepts.Types.List.Front;
export import Ph.Concepts.Types.List.Back;
 

import std;

namespace ph::type
{
	export 
	{
		template <typename... T>
		using common = std::common_type_t <T...>;

		template <typename...>
		struct typelist
		{

		};

		// template <typename T>
		// concept Typelist = requires ()
		// {

		// 	true;
		// 	// typename back_type_t <T>::type;
		// };
	}

}

using namespace ph::type;

consteval bool Typelist_test ()
{
	// static_assert (Typelist <list_t <int, char>>);

	return true;
}

static_assert (Typelist_test ());