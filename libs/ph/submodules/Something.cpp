export module Ph.Something;

import Ph.Nothing;

export namespace ph 
{
	template <typename T>
	concept Something = not Nothing <T>;

}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;
import std;

consteval auto Something_test () noexcept -> bool
{
	using namespace ph;
	static_assert (Something <char*>);
	return true;
}

static_assert (Something_test ());

#endif
