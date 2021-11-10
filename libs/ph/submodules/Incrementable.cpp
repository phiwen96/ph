export module Ph.Incrementable;

export namespace ph 
{
	template <typename T>
	concept Incrementable = requires (T t) 
	{
		t++;
		++t;
	};

}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;
import std;

consteval auto Incrementable_test () noexcept -> bool
{
	using namespace ph;
	static_assert (Incrementable <char*>);
	return true;
}

static_assert (Incrementable_test ());

#endif
