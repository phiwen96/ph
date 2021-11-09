export module Ph.Iterator.Input;

import Ph.Const;
import Ph.Reference;

export namespace ph 
{
	template <typename T>
	concept Input_iterator = requires (T& t) 
	{
		{*t} -> Const;
		t++;
		++t;
	};

	/*==================================
 	 FUNCTION DEFINITIONS
	====================================*/
	constexpr auto read (Input_iterator auto) noexcept -> Reference auto;
	constexpr auto next (Input_iterator auto) noexcept -> Input_iterator auto;
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

/*==================================
 FUNCTION IMPLEMENTATIONS
====================================*/
namespace ph 
{
	constexpr auto read (Input_iterator auto i) noexcept -> Reference auto
	{
		return *i;
	}

	constexpr auto next (Input_iterator auto i) noexcept -> Input_iterator auto
	{
		return ++i;
	}
}