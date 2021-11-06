export module Ph.Const;

namespace ph 
{
	export 
	{
		template <typename T>
		concept Const = not requires (T t0, T t1)
		{
			t0 = t1;
		};
	}
}