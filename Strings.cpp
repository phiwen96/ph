export module Ph.Concepts.Strings;

export import Ph.Concepts.String;
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
			{s [0]} -> String;
			{s [0]} -> Reference;
		};

		template <String T = str <>>
		struct strings_t 
		{

		};
	}
}

using namespace ph;
import std; 

consteval auto Strings_test () -> bool 
{
	static_assert (Strings <std::vector <std::string>>);
	static_assert (Strings <std::array <std::string, 10>>);
	static_assert (Strings <std::vector <char const*>>);

	// Strings auto s1 = {"hej", "då"};

	return true;
}


static_assert (Strings_test ());