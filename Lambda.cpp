export module Ph.Concepts.Lambda;

import Ph.Concepts.Same_as;
import Ph.Concepts.Types.List;
 

import std;

namespace ph
{
	template <typename>
	struct lambda_t;

	template <typename T, typename... U>
	struct lambda_t <T (U...)>
	{

	};

	export 
	{
		template <typename L, typename... Args>
		concept Lambda = requires (L lambda, Args... args)
		{
			lambda (args...);
		};
	}

}

using namespace ph;

consteval bool Lambda_test ()
{

	Lambda auto l1 = [] () {return 4;};

	Lambda <int> auto l2 = [] (int u) {return u;};


	

	return true;
}

static_assert (Lambda_test ());