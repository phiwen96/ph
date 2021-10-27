export module Ph.Concepts.Byte;

// import Ph.Concepts;
// import Ph.Core;
import Ph.Concepts.Size;


export 
{
	template <typename T, auto N>
	concept Byte = Size <decltype (N)> and sizeof (T) <= N;
}



module :private;

consteval auto test ()
{
	Byte <32> auto hej = "tjo";
	
	return true;
}
static_assert (test ());