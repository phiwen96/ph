export module Ph.Incrementable;

export namespace ph 
{
	template <typename T>
	concept Prefix_incrementable = requires (T t) 
	{
		++t;
	};

	template <typename T>
	concept Postfix_incrementable = requires (T t) 
	{
		t++;
	};

	template <typename T>
	concept Incrementable = Prefix_incrementable <T> or Postfix_incrementable <T>;

	constexpr auto increment (Prefix_incrementable auto i) noexcept -> Reference 
	{
		return ++i;
	}
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;
import std;

consteval auto Incrementable_test () noexcept -> bool
{
	using namespace ph;
	static_assert (Incrementable <char*>);
	return true;
}

static_assert (Incrementable_test ());

#endif
