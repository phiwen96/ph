export module Ph.Size;

import Ph.Convertible_to;
import Ph.Assert;
import std;

namespace ph 
{
	export 
	{
		template <typename T>
		concept Size = Convertible_to <T, std::size_t>;
	}
}
