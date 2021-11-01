export module Ph.Concepts.Vector;

import Ph.Concepts.Convertible_to;
import Ph.Concepts.Reference;
import Ph.Concepts.Size;
import Ph.Concepts.Common;
import Ph.Concepts.Error;

import std;


namespace ph 
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

	export 
	{
		template <typename T, Size auto S, Size auto M>
		struct vector : ph::_error
		{
			using self = vector;
			using element = T;

			constexpr vector () noexcept : _error {}, _max {M}, _data {}, _last {0}
			{
				
			}

			template <typename... U>
			constexpr vector (T &&t, U&&... u) noexcept : _error {}, _data {t, u...}, _max {sizeof... (u) + 1}, _last {sizeof... (u)}
			{


			}

			constexpr vector (vector&& o) noexcept : _error {(_error&&) o}, _data {o._data}, _max {o._max}, _last {o.last}
			{
				
			}

			constexpr vector (vector const& o) noexcept : _error {(_error const&) o}, _data {o._data}, _max {o._max}, _last {o.last}
			{
				
			}

			constexpr auto size () const noexcept -> Size auto 
			{
				return _last + 1;
			}

			constexpr element& operator [] (Size auto&& s) noexcept
			{
				return _data [s];
			}

			friend constexpr self& operator += (self& s, element const& o) noexcept
			{
				s._data [s._last + 1] = o;
				++s._last;
				return s;
			}

			friend constexpr self& operator += (self& s, self const& o) noexcept
			{ 
				return s;
			}

			friend constexpr self operator + (self s, self const& o) noexcept 
			{
				return s;
			}

			constexpr self& operator = (self&& o) noexcept 
			{
				for (auto i = 0; i < o.size (); ++i)
				{
					_data [i] = (element&&) o._data [i];
				}

				_max = o._max;
				_max = o._max;
				static_cast <_error&> (*this) = static_cast <_error&> (o);

				return *this;
			}

			constexpr self& operator = (self const& o) noexcept 
			{
				for (auto i = 0; i < o.size (); ++i)
				{
					_data [i] = o._data [i];
				}

				return *this;
			}

			constexpr self& operator = (element const& o) noexcept 
			{
				// _data [0]
				for (auto i = 1; i <= _last; ++i)
				{
					_data [i].~element ();
				}

				return *this;
			}

		private:
			element _data [M];
			std::size_t _max;
			std::size_t _last;

		};

		// template <typename T, typename... U>
		// vector (T, U...) -> vector <ph::common <T, U...>>;
		
		constexpr auto at (auto& a, Size auto&& s) noexcept 
		{
			return a [s];
		}
	}
	
}
	


consteval bool test ()
{
	using namespace ph;
	Vector auto v1 = ph::vector <int, 3, 100> {0, 1, 2};
	
	// Vector auto v2 = v1;
	v1 += 3;

	return v1 [0] == 0 and v1 [1] == 1 and v1 [2] == 2 and v1 [3] == 3 and v1.size () == 4;
}

static_assert (test ());