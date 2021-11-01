export module Ph.Concepts.Constant;

namespace ph 
{
	export 
	{
		template <typename T>
		concept Constant = not requires (T t0, T t1)
		{
			t0 = t1;
		};
	}
}