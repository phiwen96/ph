export module Ph.Range;

import Ph.Bool;
import Ph.Size;
import Ph.Pointer;
import Ph.Iterator;
import std;

template <typename T>
struct contains_proxy { T const& _value; };

export namespace ph 
{

		template <typename R>
		concept Range = requires (R r)
		{ 
			true;
			// requires rangeable (std::declval <R> ());
			// requires (rangeable (r));
			// if (true) {};
			// true; 
			// requires (rangeable (r) == true);

			// {ph::begin (r)} noexcept -> Iterator;
			// {ph::end (r)} noexcept -> Iterator;
		};

		constexpr auto range (auto&& r) -> Range auto  
		requires requires ()
		{
			{r.range ()} noexcept -> Range;
		}
		{
			return r.range ();
		}

		constexpr auto range (Range auto&& r) -> Range auto  
		{
			return r;
		}

		template <typename E>
		constexpr auto contains (E const& e) noexcept -> auto
		{
			return contains_proxy <E> {e};
		}

		template <typename T, typename E>
		constexpr auto operator | (Range auto const& r, contains_proxy <E> const& proxy) noexcept -> Bool auto
		{
			auto const& v = proxy._value;
			for (auto const& e : r)
			{
				if (e == proxy._value) return true;
			}

			return false;
		}

		template <typename T>
		struct range_t
		{
			using element = T;
			using pointer = element*;

			constexpr range_t (pointer b, pointer e) : _begin {b}, _end {e}, _max {_end}
			{

			}

			constexpr range_t (pointer b, pointer e, pointer m) : _begin {b}, _end {e}, _max {m}
			{

			}

			constexpr auto begin () noexcept -> Iterator auto 
			{
				return iterator_t <element> {_begin};
			}

			constexpr auto end () noexcept -> Iterator auto 
			{
				return iterator_t <element> {_end};
			}

			constexpr auto begin () const noexcept -> Iterator auto 
			{
				return iterator_t <element> {_begin};
			}

			constexpr auto end () const noexcept -> Iterator auto 
			{
				return iterator_t <element> {_end};
			}

			constexpr auto max () const noexcept -> Size auto 
			{
				return ptrdiff_t {_max - _begin};
			}

			constexpr auto operator [] (Size auto const& s) noexcept -> element&
			{
				return _begin [s];
			}

			constexpr auto operator [] (Size auto const& s) noexcept -> element const&
			{
				return _begin [s];
			}

			constexpr auto contains (Pointer auto const& p) const noexcept -> Bool auto 
			{
 				return std::uintptr_t (p) >= std::uintptr_t (_begin) and std::uintptr_t (p) < std::uintptr_t (_begin) + max ();
			}

			constexpr auto len () const noexcept -> Size auto 
			{
				return ptrdiff_t {_end - _begin};
			}

		protected:
			pointer _begin;
			pointer _end;
			pointer _max;
		};	
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

using namespace ph;

import Ph.Test;

	consteval auto Range_test () noexcept -> Bool auto 
	{
		Bool auto b = true;

		static_assert (Range <std::vector <int>>);

		static_assert (Range <std::array <int, 10>>);
		 

		return b;
	}

	static_assert (Range_test ());

#endif