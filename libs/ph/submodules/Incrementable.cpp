export module Ph.Incrementable;

export import Ph.Prefix_incrementable;
export import Ph.Postfix_incrementable;

export namespace ph 
{
	template <typename T>
	concept Incrementable = Prefix_incrementable <T> or Postfix_incrementable <T>;
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
