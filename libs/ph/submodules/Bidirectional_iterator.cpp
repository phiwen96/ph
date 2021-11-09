export module Ph.Iterator.Bidirectional;
import Ph.Iterator.Forward;

export namespace ph 
{
	template <typename T>
	concept Bidirectional_iterator = Forward_iterator <T> and requires (T a)
	{
		--a;
		a--;
	};

	/*==================================
 	 FUNCTION DEFINITIONS
	====================================*/
	constexpr auto begin (auto&& a) noexcept -> Bidirectional_iterator auto;
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;

consteval auto Bidirectional_iterator_test () noexcept -> bool
{
	using namespace ph;
	
	return true;
}

static_assert (Bidirectional_iterator_test ());

#endif

/*==================================
 FUNCTION IMPLEMENTATIONS
====================================*/
namespace ph 
{
	constexpr auto begin (auto&& a) noexcept -> Bidirectional_iterator auto
	requires requires 
	{
		{a.begin ()} noexcept -> Bidirectional_iterator;
	}
	{
		return a.begin ();
	}
}