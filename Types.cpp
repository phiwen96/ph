export module Ph.Concepts.Types;


export import Ph.Concepts.Types.List;

import Ph.Concepts.Bool;

import std;

namespace ph::type
{
	
	export 
	{
		template <typename... T>
		using common = std::common_type_t <T...>;
	}
}



using namespace ph;


consteval auto Types_test () noexcept -> Bool auto
{
	return true;
}


static_assert (Types_test ()); 



