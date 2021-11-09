export module Ph.Iterator.Input;

import Ph.Const;

export namespace ph 
{
	template <typename T>
	concept Input_iterator = requires (T& t)
	{
		// read only
		{*t} -> Const;
		t++;
		++t;
	};
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;

consteval auto Input_iterator_test () noexcept -> bool
{
	using namespace ph;
	
	return true;
}

static_assert (Input_iterator_test ());

#endif