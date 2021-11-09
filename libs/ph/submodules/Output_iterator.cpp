export module Ph.Iterator.Output;
import Ph.Reference;


export namespace ph 
{
	template <typename T>
	concept Output_iterator = requires (T& t)
	{
		// write only
		{*t} -> Reference;
		t++;
		++t;
	};
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;

consteval auto Output_iterator_test () noexcept -> bool
{
	using namespace ph;
	
	return true;
}

static_assert (Output_iterator_test ());

#endif