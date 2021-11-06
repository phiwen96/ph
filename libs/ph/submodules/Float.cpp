export module Ph.Number.Float;

import Ph.Convertible_to;

namespace ph 
{
	export template <typename T>
	concept Floating = Convertible_to <T, float> or Convertible_to <T, double> or Convertible_to <T, long double>;
}



