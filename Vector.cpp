export module Ph.Concepts.Vector;

import Ph.Concepts.Convertible_to;
import Ph.Concepts.Reference;
import Ph.Concepts.Size;
import Ph.Concepts.Common;

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
		template <typename T, Size auto S>
		struct vector 
		{
			using self = vector;
			using element = T;

			constexpr vector () noexcept : _data {}, _size {0}
			{
				
			}

			template <typename... U>
			constexpr vector (T &&t, U&&... u) noexcept : _data {t}, _size {sizeof... (u) + 1}
			{

			}

			// constexpr vector (T const (&) [] )
			// {

			// }


			constexpr element& operator [] (Size auto&& s) noexcept
			{
				return *(_data + s);
			}

			friend constexpr self& operator += (self& s, element const& o) noexcept
			{
				return s;
			}

			friend constexpr self& operator += (self& s,self const& o) noexcept
			{ 
				return s;
			}

			friend constexpr self operator + (self s, self const& o) noexcept 
			{
				return s;
			}

			constexpr self operator = (self const& o) noexcept 
			{
				return *this;
			}

			constexpr self operator = (element const& o) noexcept 
			{
				return *this;
			}

			private:
			element _data [S];
			std::size_t _size;
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
	Vector auto v1 = ph::vector <int, 3> {1, 2, 3};
	Vector auto v2 = v1; 
	return at (v2, 0) == 1;
}

static_assert (test ());