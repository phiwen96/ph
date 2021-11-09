export module Ph.Iterator.Random_access;
import Ph.Iterator.Bidirectional;

export namespace ph 
{
	template <typename T>
	concept Random_access_iterator = Bidirectional_iterator <T> and requires (T a)
	{
		a + 3;
	};
}

/*==================================
 TESTING
====================================*/
#ifdef Testing
import Ph.Test;

consteval auto Random_access_iterator_test () noexcept -> bool
{
	using namespace ph;
	
	return true;
}

static_assert (Random_access_iterator_test ());
#endif