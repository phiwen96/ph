export module Ph.Concepts.Byte;

import Ph.Concepts.Bit;

namespace ph 
{

export 
{
	template <typename T, auto N>
	concept Byte = Bit <T, 8 * N>;
}



// module :private;

consteval auto Byte_test ()
{
	Byte <4> auto hej = "tjo";
	
	return true;
}

static_assert (Byte_test ());
}