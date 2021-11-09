export module Ph.Iterator;

import Ph.Const;
import Ph.Reference;
import Ph.Size;
import Ph.Pointer;
import std;
export import Ph.Iterator.Input;
export import Ph.Iterator.Output;
export import Ph.Iterator.Forward;
export import Ph.Iterator.Bidirectional;
export import Ph.Iterator.Random_access;

/*
At its core, an iterator is an object that represents a position in a sequence.
*/

export namespace ph 
{
	template <typename T>
	concept Iterator = 
		Input_iterator <T> or 
		Output_iterator <T> or 
		Forward_iterator <T> or 
		Bidirectional_iterator <T> or
		Random_access_iterator <T>;

	constexpr auto begin (auto&& a) noexcept -> Iterator auto;

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

/*==================================
 IMPLEMENTATION
====================================*/

	constexpr auto begin (auto&& a) noexcept -> Iterator auto
	requires requires ()
	{
		{a.begin ()} noexcept -> Iterator;
	}
	{
		return a.begin ();
	}

	inline constexpr auto end (auto&& a) noexcept -> Iterator auto
	requires requires ()
	{
		{a.end ()} noexcept -> Iterator;
	}
	{
		return a.end ();
	}
}



/*==================================
 IMPLEMENTATION
====================================*/

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;

consteval auto Iterator_test () noexcept -> bool
{
	using namespace ph;
	
	return true;
}

static_assert (Iterator_test ());

#endif



