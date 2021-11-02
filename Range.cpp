export module Ph.Concepts.Range;

import Ph.Concepts.Reference;
import Ph.Concepts.Bool;
import Ph.Concepts.Constant;
import Ph.Concepts.Size;
import Ph.Concepts.Element;
import Ph.Concepts.Pointer;
import Ph.Concepts.Iterator;

import std;



namespace ph 
{
	template <typename T>
	struct contains_proxy { T const& _value; };

	consteval auto rangeable (auto&& r) -> Bool auto 
	{
		return true;
	}

	// template <typename T>
	// concept Rangeable = rangeable (std::declval <T> ());

	export 
	{



		template <typename R>
		concept Range = requires (R r)
		{
			// requires (rangeable (r));
			// if (true) {};
			true;
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

		

		// constexpr len (Range auto const& r) -> Size auto 
		// {
		// 	return range (r)
		// }

		template <typename E>
		constexpr auto contains (E const& e) noexcept -> auto
		{
			return contains_proxy <E> {e};
		}

		template <typename E>
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

			constexpr element& operator [] (Size auto&& s) noexcept
			{
				return _begin [s];
			}

		private:
			pointer _begin;
			pointer _end;
			pointer _max;
		};
	}
}

using namespace ph;

static_assert (Range <std::vector <int>>);
	static_assert (Range <std::array <int, 10>>);


	consteval auto test () noexcept -> Bool auto 
	{
		Bool auto b = true;
		 

		return b;
	}

	static_assert (test ());