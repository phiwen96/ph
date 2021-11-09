export module Ph.Iterator.Output;
import Ph.Reference;


export namespace ph 
{
	template <typename T>
	concept Output_iterator = requires (T& t)
	{
		// write only
		{*t} -> Reference;
		t++;
		++t;
	};

	/*==================================
 	 FUNCTION DEFINITIONS
	====================================*/
	constexpr auto begin (auto&& a) noexcept -> Output_iterator auto;
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
	constexpr auto begin (auto&& a) noexcept -> Output_iterator auto
	requires requires 
	{
		{a.begin ()} noexcept -> Output_iterator;
	}
	{
		return a.begin ();
	}
}