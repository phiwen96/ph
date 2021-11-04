export module Ph.Concepts.Lambda;

import Ph.Concepts.Convertible_to;
import Ph.Concepts.Types.List;
 

// import std;

namespace ph
{
	export 
	{
		template <typename Lam, typename... T>
		concept Lambda = requires (Lam lambda, T... t)
		{
			{lambda (t...)};
		};



	}

}

using namespace ph;

consteval bool Lambda_test ()
{

	// Lambda auto l1 = [] () {return 4;};

	// Lambda <int> auto l2 = [] (int u) {return u;};
	// Lambda <int, char*> auto l3 = [] (int u, char*) {return u;};


	

	return true;
}

static_assert (Lambda_test ());