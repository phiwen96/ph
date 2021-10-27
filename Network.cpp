export module Ph.Network;

import Ph.Concepts;
import Ph.Core;


export 
{
	template <typename T>
	concept IPv4 = String <T>;

	template <typename T>
	concept IPv6 = String <T>;
}


module :private;