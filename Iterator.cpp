export module Ph.Concepts.Iterator;

import Ph.Concepts.Constant;
import Ph.Concepts.Reference;
import Ph.Concepts.Size;
import Ph.Concepts.Bool;
import Ph.Concepts.Element;
import std;

/*
At its core, an iterator is an object that represents a position in a sequence.
*/



namespace ph 
{

	
	
	// template <typename T>
	// requires requires ()
	// {
	// 	typename T::interator;
	// }
	// struct iterator_t
	// {
	// 	using element = element <E>;
	// 	using iterator = typename E::iterator;
	// };

	

	

	export 
	{
		template <typename T>
		concept Input_iterator = requires (T& t)
		{
			// read only
			{*t} -> Constant;
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

		template <typename T>
		struct iterator_t
		{
			// using element = element <E>;
			// using iterator = std::iterator <>;
		};

		template <typename T>
		requires requires ()
		{
			requires Iterator <typename T::iterator>;
		}
		struct iterator_t <T>
		{
			using iterator = typename T::iterator;
		};

		template <typename T>
		requires requires () 
		{
			typename iterator_t <T>::iterator;
		}

		using iterator = typename iterator_t <T>::iterator;

	


	}

	consteval auto test () noexcept -> Bool auto
	{
		Bool auto b = true;
		iterator <std::vector <int>> i0;
		iterator <std::array <int, 1>> i1;

		return b;
	}

	static_assert (test ());

}