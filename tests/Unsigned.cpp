export module Ph.Number.Unsigned;

import Ph.Convertible_to;
import Ph.Assert;


namespace ph 
{
	export template <typename T>
	concept Unsigned = Convertible_to <T, unsigned short>
		or Convertible_to <T, unsigned short int>
		or Convertible_to <T, unsigned>
		or Convertible_to <T, unsigned int>
		or Convertible_to <T, unsigned long>
		or Convertible_to <T, unsigned long int>
		or Convertible_to <T, unsigned long long>
		or Convertible_to <T, unsigned long long int>;
}


consteval auto Unsigned_test () -> bool
{
	using namespace ph;

	constexpr auto assert_unsigned = [] <Unsigned> {};
	constexpr auto assert_not_unsigned = [] <typename T> requires (not Unsigned <T>) {};
	
	return true;
}

static_assert (Unsigned_test ());

