export module Ph.Concepts.Bool;

import Ph.Concepts.Convertible_to;

namespace ph 
{

export template <typename T>
concept Bool = Convertible_to <T, bool>;

}