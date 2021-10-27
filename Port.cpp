export module Ph.Network.Port;

import Ph.Concepts;

export 
{
	template <typename T>
	concept Port = Number <T> and Byte <T, 2>;
}

// module :private;

consteval auto Port_test ()
{
	Port auto p0 = 1;

	return true;
}

static_assert (Port_test ());
