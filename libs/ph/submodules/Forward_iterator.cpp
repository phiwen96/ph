export module Ph.Iterator.Forward;
import Ph.Iterator.Input;
import Ph.Iterator.Output;

export namespace ph 
{
	/*==================================
 	 CONCEPTS
	====================================*/
	template <typename T>
	concept Forward_iterator = 
		Input_iterator <T> and 
		Output_iterator <T>;

	/*==================================
 	 FUNCTION DEFINITIONS
	====================================*/
	constexpr auto begin (Forward_iterator auto&& a) noexcept -> Forward_iterator auto;
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


/*==================================
 FUNCTION IMPLEMENTATIONS
====================================*/
namespace ph 
{
	constexpr auto begin (auto&& a) noexcept -> Forward_iterator auto
	requires requires 
	{
		{a.begin ()} noexcept -> Forward_iterator;
	}
	{
		return a.begin ();
	}
}