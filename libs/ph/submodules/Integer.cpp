export module Ph.Number.Integer;

import Ph.Convertible_to;

export namespace ph 
{
	template <typename T>
    concept Integer = Convertible_to <T, short>
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
        or Convertible_to <T, signed long long int>
        or Convertible_to <T, unsigned short>
        or Convertible_to <T, unsigned short int>
        or Convertible_to <T, unsigned>
        or Convertible_to <T, unsigned int>
        or Convertible_to <T, unsigned long>
        or Convertible_to <T, unsigned long int>
        or Convertible_to <T, unsigned long long>
        or Convertible_to <T, unsigned long long int>;
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;

consteval bool Integer_test () 
{
	using namespace ph;

	constexpr auto assert_integer = [] <Integer> {};
	constexpr auto assert_not_integer = [] <typename T> requires (not Integer <T>) {};

	test::assert_all <int, int&, int&&, bool, char, float, double, long double> (assert_integer);
	test::assert_all <char const*, int const (&) [10]> (assert_not_integer);

	return true;
}

static_assert (Integer_test ());

#endif