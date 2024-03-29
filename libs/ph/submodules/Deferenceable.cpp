export module Ph.Dereferenceable;

import Ph.Something;
import Ph.Mimic;


export namespace ph 
{
	template <typename T>
	concept Dereferenceable = requires (T t)
	{
		{*t} -> Something;
	};

	constexpr auto derefer (Dereferenceable auto && d) noexcept -> decltype (auto)
	{
		return *d;
	}

	namespace type 
	{
		template <Dereferenceable D> 
		using derefer = decltype (ph::derefer (mimic <D> ()));
	}
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;
import std;

consteval auto Dereferenceable_test () noexcept -> bool
{
	using namespace ph;
	static_assert (Dereferenceable <char*>);
	return true;
}

static_assert (Dereferenceable_test ());

#endif
