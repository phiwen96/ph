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

	/*==================================
 	 FUNCTION DEFINITIONS
	====================================*/
	constexpr auto begin (auto&& a) noexcept -> Input_iterator auto;
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
	constexpr auto begin (auto&& a) noexcept -> Input_iterator auto
	requires requires 
	{
		{a.begin ()} noexcept -> Input_iterator;
	}
	{
		return a.begin ();
	}
}