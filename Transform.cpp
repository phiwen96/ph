export module Ph.Concepts.Types.List.Transform;



namespace ph
{
	export 
	{
		template <typename T>
		concept Transform = requires (T t)
		{
			true;
		};
	}
}

using namespace ph;

consteval bool Transform_test ()
{

	return true;
}

static_assert (Transform_test ());