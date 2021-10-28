export module Ph.Concepts.Boolean;

import Ph.Concepts.Convertible_to;


export template <typename T>
concept Boolean = Convertible_to <T, bool>;
