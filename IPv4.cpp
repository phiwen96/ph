export module Ph.Network.IPv4;

import Ph.Concepts;


export 
{
	template <typename T>
	concept IPv4 = Byte <T, 4> and String <T>;
}



export 
{
	constexpr auto loop_back_IPv4 () noexcept -> IPv4 auto
	{
		return "127.0.0.1";
	}
}

// module :private;

consteval auto IPv4_test ()
{
	IPv4 auto i0 = "192.0.2.111";

	return true;
}

static_assert (IPv4_test ());