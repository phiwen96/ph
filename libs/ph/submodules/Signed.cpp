export module Ph.Number.Signed;

import Ph.Convertible_to;
import Ph.Assert;


namespace ph 
{
	export 
	{
		template <typename T>
		concept Signed = Convertible_to <T, short>
			or Convertible_to <T, short int>
			or Convertible_to <T, signed short>
			or Convertible_to <T, signed short int>
			or Convertible_to <T, int>
			or Convertible_to <T, signed>
			or Convertible_to <T, signed int>
			or Convertible_to <T, long>
			or Convertible_to <T, long int>
			or Convertible_to <T, signed long>
			or Convertible_to <T, signed long int>
			or Convertible_to <T, long long>
			or Convertible_to <T, long long int>
			or Convertible_to <T, signed long long>
			or Convertible_to <T, signed long long int>;
	}
}




/*==================================
 TESTING
====================================*/
#ifdef Testing

consteval auto Signed_test () -> bool
{
	using namespace ph;

	constexpr auto assert_signed = [] <Signed> {};
	constexpr auto assert_not_signed = [] <typename T> requires (not Signed <T>) {};
	
	return true;
}

static_assert (Signed_test ());

#endif