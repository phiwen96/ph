export module Ph.Iterator.Traits;
import Ph.Pointer;

export namespace ph 
{
	template <typename T>
	struct iterator_traits 
	{
		
	};

	template <Pointer P>
	struct iterator_traits <P>
	{
		using element = remove_pointer <P>;
	};

	/*==================================
 	 FUNCTION DEFINITIONS
	====================================*/
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;

consteval auto Iterator_traits_test () noexcept -> bool
{
	using namespace ph;
	
	return true;
}

static_assert (Iterator_traits_test ());

#endif

/*==================================
 FUNCTION IMPLEMENTATIONS
====================================*/
