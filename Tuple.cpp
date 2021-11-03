export module Ph.Concepts.Tuple;

namespace ph 
{
	export 
	{
		template <typename T>
		concept Tuple = requires (T t)
		{
			true;
		};

		
		struct tuple_t 
		{

		};
	}
}

using namespace ph;

consteval auto Tuple_test () noexcept -> bool 
{

	return true;
}

static_assert (Tuple_test ());