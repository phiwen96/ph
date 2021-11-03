export module Ph.Concepts.Char;

import Ph.Concepts.Convertible_to;

namespace ph 
{
	export 
	{
		template <typename T>
		concept Char = 
			Convertible_to <T, char>
			or Convertible_to <T, signed char>
			or Convertible_to <T, unsigned char>
			or Convertible_to <T, char16_t>
			or Convertible_to <T, char32_t>
			or Convertible_to <T, wchar_t>;
	}
}


using namespace ph;

consteval bool Char_test ()
{
	return true;
}


static_assert (Char_test ());

