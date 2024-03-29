export module Ph.Iterator;

import Ph.Const;
import Ph.Reference;
import Ph.Size;
import Ph.Bool;
import Ph.Pointer;
import std;

/*
At its core, an iterator is an object that represents a position in a sequence.
*/



namespace ph 
{
	export 
	{
		template <typename T>
		concept Input_iterator = requires (T& t)
		{
			// read only
			{*t} -> Const;
			t++;
			++t;
		};

		template <typename T>
		concept Output_iterator = requires (T& t)
		{
			// write only
			{*t} -> Reference;
			t++;
			++t;
		};

		template <typename T>
		concept Forward_iterator = Input_iterator <T> and Output_iterator <T>;

		template <typename T>
		concept Bidirectional_iterator = Forward_iterator <T> and requires (T a)
		{
			--a;
			a--;
		};

		template <typename T>
		concept Random_access_iterator = Bidirectional_iterator <T> and requires (T a)
		{
			a + 3;
		};

		template <typename T>
		concept Iterator = Input_iterator <T> or Output_iterator <T> or Forward_iterator <T> or Bidirectional_iterator <T> or Random_access_iterator <T>;

		template <typename T>
		concept Raw_iterator = Pointer <T>;


		template <typename T>
		struct iterator_t
		{
			using self = iterator_t;
			using element = T;
			using pointer = element*;

			constexpr iterator_t (pointer c) noexcept : _current {c}
			{

			}

			constexpr iterator_t (iterator_t&& o) : _current {(pointer&&) o.current}
			{

			}

			constexpr iterator_t (iterator_t const& o) : _current {o._current}
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






		// inline constexpr auto begin (Raw_iterator auto&& r1, Raw_iterator auto&& r2) noexcept -> Iterator auto 
		// {
		// 	return iterator_t {r1, r2};
		// }

		inline constexpr auto begin (auto&& a) noexcept -> Iterator auto
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



		template <Iterator I>
		using iterator = iterator_t <I>; 
	}

	

}



consteval auto Iterator_test () noexcept -> bool
{
	using namespace ph;

	return true;
}

static_assert (Iterator_test ());
