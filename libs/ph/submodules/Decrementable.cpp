export module Ph.Decrementable;

export namespace ph 
{
	template <typename T>
	concept Decrementable = requires (T t) 
	{
		t--;
		--t;
	};

}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;
import std;

consteval auto Decrementable_test () noexcept -> bool
{
	using namespace ph;
	static_assert (Decrementable <char*>);
	return true;
}

static_assert (Decrementable_test ());

#endif
