export module Ph.Concepts.Types.List.Back;

namespace ph::type
{
	export 
	{
		template <typename T>
		concept Back = requires ()
		{
			true;
		};
	}
}



using namespace ph;


consteval auto Back_test () noexcept -> bool
{
	return true;
}


static_assert (Back_test ()); 
