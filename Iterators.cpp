export module Ph.Concepts.Iterators;

import Ph.Concepts.Core;


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
		{*t} -> Ref;
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
	{
		return a.begin ();
	}

	inline constexpr auto end (auto&& a) -> Iterator auto
	{
		return a.end ();
	}
}

// module :private;

}