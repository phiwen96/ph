export module Ph.Concepts.Byte;

import Ph.Concepts.Bit;


export 
{
	template <typename T, auto N>
	concept Byte = Bit <T, 8 * N>;
}



module :private;

consteval auto test ()
{
	Byte <4> auto hej = "tjo";
	
	return true;
}

static_assert (test ());