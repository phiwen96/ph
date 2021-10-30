export module Ph.Concepts.Floating;

import Ph.Concepts.Convertible_to;

export 
{
	template <typename T>
	concept Floating = Convertible_to <T, float> or Convertible_to <T, double> or Convertible_to <T, long double>;
}