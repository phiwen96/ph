export module Ph.Network;

import Ph.Concepts;
import Ph.Core;


export 
{
	template <typename T>
	concept IPv4 = Byte <T, 4> and String <T>;

	template <typename T>
	concept IPv6 = Byte <T, 16> and String <T>;
}



export 
{
	constexpr auto loop_back_IPv4 () noexcept -> IPv4 auto
	{
		return "127.0.0.1";
	}

	constexpr auto loop_back_IPv6 () noexcept -> IPv6 auto
	{
		return "::1";
	}
}

module :private;

consteval auto Network_test ()
{
	IPv4 auto i0 = "192.0.2.111";
	IPv6 auto i1 = "2001:0db8:c9d2:aee5:73e3:934a:a5ae:9551";

	return true;
}

static_assert (Network_test ());