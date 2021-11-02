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
		struct vector : range_t <T>
		{
			using self = vector;
			using element = T;

			constexpr vector () noexcept : _data {}, range_t <element> {_data, _data + S, _data + M}
			{
				return range_t <T> {};
			}

			template <typename... U>
			requires requires () {requires Convertible_to <common <U...>, element>;}
			constexpr vector (U&&... u) noexcept : _data {(element&&) u...}, range_t <element> {_data, _data + S, _data + M}
			{

			}
			
		private:
			element _data [M];
		};
	}
	
}
	


consteval bool test ()
{
	using namespace ph;

	Bool auto value = true;

	// Vector auto v1 = ph::vector <int, 3, 100> {0, 1, 2};

	// value = v1 [0] == 0 and v1 [1] == 1 and v1 [2] == 2 and len (v1) == 3;


	// Vector auto v2 = ph::vector <int, 2, 100> {0, 3};

	// value = value and (v2 [0] == 0 and v2 [1] == 3 and len (v2) == 2);

	// v2 += v1;

	// value = value and (v2 [0] == 0 and v2 [1] == 3) and v2 [2] == 0;



	// Vector auto v3 = v1;




	// v1 += 3;

	return value;
}

static_assert (test ());