export module Ph.Concepts.Memory.Size;

import Ph.Concepts.Convertible_to;
import std;

namespace ph 
{

export 
{
	template <typename T>
	concept Size = Convertible_to <T, std::size_t>;
}

    
}