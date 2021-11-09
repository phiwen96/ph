export module Ph.Iterator.Forward;
import Ph.Iterator.Input;
import Ph.Iterator.Output;

export namespace ph 
{
	template <typename T>
	concept Forward_iterator = Input_iterator <T> and Output_iterator <T>;
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;

consteval auto Forward_iterator_test () noexcept -> bool
{
	using namespace ph;
	
	return true;
}

static_assert (Forward_iterator_test ());

#endif