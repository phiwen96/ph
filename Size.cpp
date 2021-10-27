export module Ph.Concepts.Size;

import Ph.Concepts.Core;
import std;

export 
{
	template <typename T>
	concept Size = Convertible_to <T, std::size_t>;
}

    