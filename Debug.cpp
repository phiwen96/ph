export module Ph.Debug;

namespace ph 
{
	export 
	{
		template <typename D>
		concept Debug = requires (D d)
		{
			true;
		};
	}
}