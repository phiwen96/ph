export module Ph.Forward;

export namespace ph 
{
	/*==================================
 	 FUNCTION DEFINITIONS
	====================================*/
	template <typename T>
	constexpr auto fwd (T&&) noexcept -> decltype (auto);
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;

consteval auto Forward_test () noexcept -> bool
{
	using namespace ph;
	
	return true;
}

static_assert (Forward_test ());

#endif

/*==================================
 FUNCTION IMPLEMENTATIONS
====================================*/
namespace ph 
{
	template <typename T>
	constexpr auto fwd (T&& x) noexcept -> decltype (auto)
	{
		return static_cast <T&&> (x);  
	}
}

