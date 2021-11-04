export module Ph.Concepts.Types.Meta_function;


namespace ph 
{
	export 
	{
		template <template <typename> typename M>
		concept Meta_function = requires ()
		{
			true;
		};

	}
}


using namespace ph;

consteval bool Meta_function_test ()
{

	return true;
}

static_assert (Meta_function_test ());


