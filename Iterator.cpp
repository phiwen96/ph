export module Ph.Concepts.Iterator;

import Ph.Concepts.Constant;
import Ph.Concepts.Reference;

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



	inline constexpr auto begin (auto&& a) -> Iterator auto
	requires requires ()
	{
		{a.begin ()} -> Iterator;
	}
	{
		return a.begin ();
	}

	inline constexpr auto end (auto&& a) -> Iterator auto
	requires requires ()
	{
		{a.end ()} -> Iterator;
	}
	{
		return a.end ();
	}


	struct iterator 
	{

	};


}

	consteval bool test ()
	{

		return true;
	}

	static_assert (test ());

}