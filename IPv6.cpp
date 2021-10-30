export module Ph.Network.IPv6;

import Ph.Concepts;

namespace ph 
{

export 
{
	template <typename T>
	concept IPv6 = Byte <T, 16> and String <T>;
}



export 
{
	constexpr auto loop_back_IPv6 () noexcept -> IPv6 auto
	{
		return "::1";
	}
}

// module :private;

consteval auto IPv6_test ()
{
	IPv6 auto i0 = "2001:0db8:c9d2:aee5:73e3:934a:a5ae:9551";

	return true;
}

static_assert (IPv6_test ());

}