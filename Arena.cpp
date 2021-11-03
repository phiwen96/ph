export module Ph.Concepts.Memory.Arena;

import Ph.Concepts.Bool;
import Ph.Concepts.Range;
import Ph.Concepts.Memory.Size;
import Ph.Concepts.Types;
import Ph.Concepts.Convertible_to;


namespace ph 
{
	export 
	{
		template <typename A>
		concept Arena = requires (A a)
		{
			true;
		};

		template <typename T, Size auto S, Size auto M>
		struct arena : range_t <T>
		{
			using self = arena;
			using element = T;

			constexpr arena () noexcept : _data {}, range_t <element> {_data, _data + S, _data + M}
			{
				return range_t <T> {};
			}

			template <typename... U>
			requires requires () {requires Convertible_to <type::common <U...>, element>;}
			constexpr arena (U&&... u) noexcept : _data {(element&&) u...}, range_t <element> {_data, _data + S, _data + M}
			{

			}

			constexpr friend auto operator + (self lhs, self const& rhs)
			{
			
			}
			
		private:
			element _data [M];
		};
	}
}


using namespace ph;

consteval auto Arena_test () noexcept -> Bool auto 
{
	


	return true;
}

static_assert (Arena_test ());