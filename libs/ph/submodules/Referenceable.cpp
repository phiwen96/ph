export module Ph.Referenceable;

import Ph.Something;

export namespace ph 
{
	template <typename T>
	concept Referenceable = requires (T t)
	{
		{&t} -> Something;
	};

}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;
import std;

consteval auto Referenceable_test () noexcept -> bool
{
	using namespace ph;
	static_assert (Referenceable <char*>);
	static_assert (not Referenceable <void>);
	return true;
}

static_assert (Referenceable_test ());

#endif
