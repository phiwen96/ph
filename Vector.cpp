export module Ph.Concepts.Vector;

import Ph.Concepts.Convertible_to;
import Ph.Concepts.Reference;
import Ph.Concepts.Size;

namespace ph 
{
	template <typename V>
	concept Vector = requires (V v1, V v2, ph::remove_reference <decltype (v1 [0])> e1)
	{
		{v1 += e1} -> Reference; 
		{v1 += v2} -> Convertible_to <V>;

		{v1 + v2} -> Convertible_to <V>;
		
		{v1 [0]} -> Reference;

		{v1 += e1} -> Reference; 
		{v1 += e1} -> Convertible_to <V>;
	};

	export 
	{
		struct vector 
		{
			using self = vector;
			using element = self;

			constexpr auto operator [] (Size auto&& s) -> element&
			{
				return *this;
			}

			friend constexpr self& operator += (self& s, element const& o)
			{
				return s;
			}

			friend constexpr self& operator += (self& s, self&& o)
			{
				return s;
			}

			friend constexpr self operator + (self s, self const& o)
			{
				return s;
			}

			private:
			
		};
	}
	
}

consteval bool test ()
{
	using namespace ph;
	static_assert (Vector <vector>);
	constexpr Vector auto v1 = vector {};
	return true;
}

static_assert (test ());