export module Ph.Network;

import Ph.Concepts;
import Ph.Core;


export 
{
	template <typename T>
	concept IPv4 = Byte <T, 32>;

	template <typename T>
	concept IPv6 = String <T>;
}


module :private;