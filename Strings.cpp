export module Ph.Concepts.Strings;

import Ph.Concepts.String;
import Ph.Concepts.Range;
import Ph.Concepts.Char;
import Ph.Concepts.Reference;


namespace ph 
{
	export 
	{
		template <typename S>
		concept Strings = Range <S> and requires (S s) 
		{
			{s [0]} -> Char;
			{s [0]} -> Reference;
		};
	}
}

using namespace ph;

consteval auto Strings_test () -> bool 
{

	return true;
}


static_assert (Strings_test ());