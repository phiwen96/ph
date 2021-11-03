export module Ph.Concepts.Types.List.Front;

namespace ph
{
	export 
	{
		template <typename T>
		concept Front = requires ()
		{
			true;
		};
	}
}



using namespace ph;


consteval auto Front_test () noexcept -> bool
{
	return true;
}


static_assert (Front_test ()); 
