export module Ph.Iterator.Random_access;
import module Ph.Iterator.Bidirectional;

template <typename T>
concept Random_access_iterator = Bidirectional_iterator <T> and requires (T a)
{
	a + 3;
};

/*==================================
 TESTING
====================================*/
#ifdef Testing
import Ph.Test;

consteval auto Iterator_test () noexcept -> bool
{
	using namespace ph;
	
	return true;
}

static_assert (Iterator_test ());
#endif