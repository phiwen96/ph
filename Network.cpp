export module Ph.Network;

import Ph.Concepts;
import Ph.Core;

export import Ph.Network.IPv4;
export import Ph.Network.IPv6;


module :private;

consteval auto Network_test ()
{
	return true;
}

static_assert (Network_test ());