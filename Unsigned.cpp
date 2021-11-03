export module Ph.Concepts.Number.Unsigned;

import Ph.Concepts.Convertible_to;

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