export module Ph.Concepts.Char;

import Ph.Concepts.Core;

namespace ph 
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