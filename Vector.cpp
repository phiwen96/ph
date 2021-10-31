export module Ph.Concepts.Vector;

import Ph.Concepts.Convertible_to;
import Ph.Concepts.Reference;

namespace ph 
{
	template <typename V>
	concept Vector = requires (V v1, V v2, ph::remove_reference <decltype (v1 [0])> e1)
	{
		{v1 += e1} -> Reference; 
		{v1 += v2} -> Convertible_to <V>;

		{v1 + v2} -> Convertible_to <V>;
		
		{v1 [0]} -> Reference;
		
		{v1 += e1} -> Reference; 
		{v1 += e1} -> Convertible_to <V>;
	};

	export 
	{
		struct vector 
		{
			
		};
	}
	
}

consteval bool test ()
{
	using namespace ph;

	return true;
}

static_assert (test ());