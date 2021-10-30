export module Ph.Concepts.Any_of;

import Ph.Concepts.Same_as;


namespace ph 
{
	export 
	{
		template <typename A, typename B, typename... C>
		concept Any_of = true;//Same_as <A, B> or Same_as <A, C...>;
	}
}