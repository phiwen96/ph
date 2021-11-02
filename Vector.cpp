export module Ph.Concepts.Vector;

import Ph.Concepts.Convertible_to;
import Ph.Concepts.Reference;
import Ph.Concepts.Size;
import Ph.Concepts.Common;
import Ph.Concepts.Error;
import Ph.Concepts.Bool;
import Ph.Concepts.Array;
import Ph.Concepts.Pointer;
// import Ph.Concepts.Iterator;
import Ph.Concepts.Range;

import std;


namespace ph 
{
	export 
	{
		template <typename V>
		concept Vector = requires (V v1, V v2, ph::remove_reference <decltype (v1 [0])> e1, ph::remove_reference <decltype (v1 [0])> e2)
		{
			{v1 += e1} -> Reference; 
			{v1 += v2} -> Convertible_to <V>;
			{v1 = e1} -> Convertible_to <V>; 
			{v1 = v2} -> Convertible_to <V>; 

			{v1 + v2} -> Convertible_to <V>;
			
			{v1 [0]} -> Reference;

			{v1 += e1} -> Reference; 
			{v1 += e1} -> Convertible_to <V>;
			V {v1};
			
			// V {e1, e2};
			
		};

		template <typename T, Size auto S, Size auto M>
		struct vector : ph::_error, ph::range_t <T>
		{
			using self = vector;
			using element = T;

			constexpr vector () noexcept : _error {}, _max {M}, _begin {}, _end {0}
			{
				
			}

			template <typename... U>
			constexpr vector (T &&t, U&&... u) noexcept : _error {}, _begin {t, u...}, _max {M}, _end {sizeof... (u)}, range_t {_begin, _end, _max}
			{


			}

			constexpr vector (vector&& o) noexcept : _error {(_error&&) o}, _begin {o._begin}, _max {M}, _end {o._end}, range_t {_begin, _end, _max}
			{
				
			}

			constexpr vector (vector const& o) noexcept : _error {(_error const&) o}, _begin {}, _max {M}, _end {o._end}, range_t {_begin, _end, _max}
			{
				for (auto i = 0; i < size (); ++i)
				{
					_begin [i] = o._begin [i];
				}
			}


			friend constexpr self& operator += (self& s, element const& o) noexcept
			{
				s._begin [s._end + 1] = o;
				++s._end;
				return s;
			}

			friend constexpr self& operator += (self& s, self const& o) noexcept
			{ 
				Size auto const n = s.size ();

				for (auto i = 0; i < o.size (); ++i)
				{
					s [n + i] = o [i];
				}

				s._end += o.size () - 1;

				return s;
			}

			friend constexpr self operator + (self s, self const& o) noexcept 
			{
				return s;
			}

			// constexpr self& operator = (self&& o) noexcept 
			// {
			// 	for (auto i = 0; i < o.size (); ++i)
			// 	{
			// 		_begin [i] = (element&&) o._begin [i];
			// 	}

			// 	_max = o._max;
			// 	_end = o._end;
			// 	static_cast <_error&> (*this) = static_cast <_error&> (o);

			// 	return *this;
			// }

			constexpr self& operator = (self const& o) noexcept 
			{
				for (auto i = 0; i < o.size (); ++i)
				{
					_begin [i] = o._begin [i];
				}

				return *this;
			}

			constexpr self& operator = (element const& o) noexcept 
			{ 
				// _begin [0]
				for (auto i = 0; i <= _end; ++i)
				{
					_begin [i].~element ();
				}

				return *this;
			}

		private:
			element _begin [M];
			std::size_t _max;
			std::size_t _end;

		};
	}
	
}
	


consteval bool test ()
{
	using namespace ph;

	Bool auto value = true;

	Vector auto v1 = ph::vector <int, 3, 100> {0, 1, 2};

	value = v1 [0] == 0 and v1 [1] == 1 and v1 [2] == 2 and len (v1) == 3;

	// value = value and (v1 == v1);

	Vector auto v2 = ph::vector <int, 2, 100> {0, 3};

	value = value and (v2 [0] == 0 and v2 [1] == 3 and len (v2) == 2);

	v2 += v1;

	value = value and (v2 [0] == 0 and v2 [1] == 3) and v2 [2] == 0;

	// value = value and (v2 [3] == 1);


	// value = value and (v1 != v2);



	Vector auto v3 = v1;

	// value = value and (v2 [0] == 0 and v2 [1] == 1 and v2 [2] == 2 and v2.size () == 3);



	v1 += 3;

	return value;
}

static_assert (test ());