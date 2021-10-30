export module Ph.Get;

export 
{
	template <typename G>
	concept Get = requires (G g)
	{
		true;
	};
}

