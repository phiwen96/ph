export module Ph.Iterator.Bidirectional;
import Ph.Iterator.Forward;

export namespace ph 
{
	template <typename T>
	concept Bidirectional_iterator = Forward_iterator <T> and requires (T a)
	{
		--a;
		a--;
	};
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;

consteval auto Bidirectional_iterator_test () noexcept -> bool
{
	using namespace ph;
	
	return true;
}

static_assert (Bidirectional_iterator_test ());

#endif