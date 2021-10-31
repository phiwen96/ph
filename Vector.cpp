export module Ph.Concepts.Vector;

import Ph.Concepts.Convertible_to;
import Ph.Concepts.Reference;
import Ph.Concepts.Size;
import Ph.Concepts.Common;




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
		template <typename T>
		struct vector 
		{
			using self = vector;
			using element = T;

			constexpr vector () noexcept 
			{
				
			}

			constexpr vector (T const&...) noexcept 
			{

			}

			// constexpr vector (T const (&) [] )
			// {

			// }


			constexpr element& operator [] (Size auto&& s) noexcept
			{
				return *this;
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
		};

		// template <typename T, typename... U>
		// vector (T, U...) -> vector <ph::common <T, U...>>;
		
	}
	
}
	


consteval bool test ()
{
	using namespace ph;
	Vector auto v1 = ph::vector <int> {1, 2, 3};
	return true;
}

static_assert (test ());