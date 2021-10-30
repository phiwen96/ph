export module Ph.Concepts.String;

// import <iostream>;
// import <string>;
import Ph.Concepts.Core;
import Ph.Concepts.Char;
import Ph.Concepts.Size;
import Ph.Concepts.Array;

import std;


export 
{
	constexpr auto c_string (auto&& s) noexcept -> char const*
	requires requires () 
	{
		{s.c_str ()} -> Convertible_to <char const*>;
	}
	{
		return s.c_str ();
	}

	constexpr auto c_string (Convertible_to <char const*> auto && s) noexcept -> char const*
	{
		return s;
	}


	constexpr auto len (auto&& s) -> Size auto 
	requires requires () 
	{
		{strlen (s)} -> Size;
	}
	{
		return strlen (s);
	}

	

	// template <typename T>
	// constexpr auto to () noexcept -> Integer auto;


	constexpr auto to (Array auto&& a) noexcept -> Integer auto 
	{
		return 2;
	}

}

export 
{
	template <typename T>
	concept String = requires (T t)
	{
		c_string (t);
		len (t);
	};
}



// module :private;

static_assert (String <std::string>);
