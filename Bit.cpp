export module Ph.Concepts.Bit;

namespace ph 
{

export 
{
	template <typename T, auto N>
	concept Bit = sizeof (T) <= N;
}



// module :private;

consteval auto test ()
{
	Bit <32> auto hej = "tjo";
	
	return true;
}

static_assert (test ());

}