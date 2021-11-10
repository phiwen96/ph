export module Ph.Mimic;

import std;


export namespace ph 
{
	template <typename T>
	constexpr auto mimic () noexcept -> decltype (auto)
	{
		return std::declval <T> ();
	}
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;
import std;

consteval auto Mimic_test () noexcept -> bool
{
	using namespace ph;
	return true;
}

static_assert (Mimic_test ());

#endif
