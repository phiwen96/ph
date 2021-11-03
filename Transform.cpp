export module Ph.Concepts.Types.List.Transform;



namespace ph
{
	template <typename...>
	struct tup {};


	export 
	{
		template <typename T>
		concept Transform = requires (T t)
		{
			typename T::template transform <tup>;
		};
	}
}

using namespace ph;

consteval bool Transform_test ()
{

	return true;
}

static_assert (Transform_test ());