export module Ph.Iterator.Output;
import Ph.Reference;
import Ph.Iterator.Traits;


export namespace ph 
{
	template <typename T>
	concept Output_iterator = requires (T t1, T t2)
	{
		*t1 = *t2;
		t1++;
		++t1;
	};

	/*==================================
 	 FUNCTION DEFINITIONS
	====================================*/
	constexpr auto write (Output_iterator auto) noexcept -> Reference auto;
	constexpr auto next (Output_iterator auto) noexcept -> Output_iterator auto;
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;

consteval auto Output_iterator_test () noexcept -> bool
{
	using namespace ph;
	
	return true;
}

static_assert (Output_iterator_test ());

#endif

/*==================================
 FUNCTION IMPLEMENTATIONS
====================================*/
namespace ph 
{

	constexpr auto write (Output_iterator auto) noexcept -> Reference auto
	{
		
	}

	constexpr auto next (Output_iterator auto) noexcept -> Output_iterator auto
	{

	}
}