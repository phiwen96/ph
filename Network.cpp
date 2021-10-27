export module Ph.Network;

import Ph.Concepts;
import Ph.Core;


export 
{
	template <typename T>
	concept IPv4 = Byte <T, 4>;

	template <typename T>
	concept IPv6 = Byte <T, 16>;
}


module :private;