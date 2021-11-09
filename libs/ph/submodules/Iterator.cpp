export module Ph.Iterator;

/*
At its core, an iterator is an object that represents a position in a sequence.
*/

import Ph.Const;
import Ph.Reference;
import Ph.Size;
import std;

export import Ph.Iterator.Input;
export import Ph.Iterator.Output;
export import Ph.Iterator.Forward;
export import Ph.Iterator.Bidirectional;
export import Ph.Iterator.Random_access;

export namespace ph 
{
	template <typename T>
	concept Iterator = 
		Input_iterator <T> or 
		Output_iterator <T> or 
		Forward_iterator <T> or 
		Bidirectional_iterator <T> or
		Random_access_iterator <T>;

	constexpr auto next (Iterator auto) noexcept -> Iterator auto;
	constexpr auto prev (Iterator auto) noexcept -> Iterator auto;
	constexpr auto advance (Iterator auto, Size auto) noexcept -> Iterator auto;

	template <typename T>
	struct iterator_t
	{
		using self = iterator_t;
		using element = T;
		using pointer = element*;

		constexpr iterator_t (pointer c) noexcept : _current {c}
		{

		}

		constexpr iterator_t (iterator_t&& o) noexcept : _current {(pointer&&) o.current}
		{

		}

		constexpr iterator_t (iterator_t const& o) noexcept : _current {o._current}
		{
				
		}

		constexpr auto operator* () noexcept -> Reference auto
		{
			return *_current;
		}

		constexpr auto operator++ () noexcept -> Reference auto
		{
			++_current;
			return *this;
		}

		constexpr auto operator++ (int) noexcept -> Reference auto 
		{
			++_current;
			return *this;
		}

		constexpr auto operator-- () noexcept -> Reference auto 
		{
			--_current;
			return *this;
		}

		constexpr auto operator-- (int) noexcept -> Reference auto
		{
			--_current;
			return *this;
		}

	private:
		pointer _current;
	};
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;

consteval auto Iterator_test () noexcept -> bool
{
	using namespace ph;

	constexpr auto assert_iterator = [] <Iterator> {};
	constexpr auto assert_not_iterator = [] <typename T> requires Iterator <T> {};
	
	// testing::assert_all <>

	return true;
}

static_assert (Iterator_test ());

#endif


/*==================================
 IMPLEMENTATION
====================================*/
namespace ph 
{
	constexpr auto next (Iterator auto i) noexcept -> Iterator auto
	{
		return ++i;
	}

	constexpr auto prev (Iterator auto i) noexcept -> Iterator auto
	{
		return --i;
	}

	constexpr auto advance (Iterator auto i, Size auto s) noexcept -> Iterator auto
	{

	}
}

