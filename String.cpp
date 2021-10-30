export module Ph.Concepts.String;

import Ph.Concepts.Convertible_to;
import Ph.Concepts.Integer;
import Ph.Concepts.Floating;
import Ph.Concepts.Char;
import Ph.Concepts.Size;
import Ph.Concepts.Array;
import Ph.Concepts.Numbers;

import std;

namespace ph 
{



export 
{
	constexpr auto c_string (auto&& s) noexcept -> char const* requires requires () {
		{s.c_str ()} -> Convertible_to <char const*>;
	}
	{
		return s.c_str ();
	}

	constexpr auto c_string (Convertible_to <char const*> auto && s) noexcept -> char const*
	{
		return s;
	}

	constexpr auto len (auto&& s) -> Size auto requires requires () {
		{strlen (s)} -> Size;}
	{
		return strlen (s);
	}

	template <typename T>
	concept String = requires (T t)
	{
		c_string (t);
		len (t);
	};

	constexpr auto to_string (Integer auto&& i) noexcept -> String auto;
	constexpr auto to_number (String auto&& s) noexcept -> Number auto;
	constexpr auto to_integer (String auto&& s) noexcept -> Integer auto;
	constexpr auto to_double (String auto&& s) noexcept -> Floating auto;
	constexpr auto to_long_integer (String auto&& s) noexcept -> Integer auto;
}




static_assert (String <std::string>);



constexpr auto to_string (Integer auto&& i) noexcept -> String auto 
	{
		char s [33];

		itoa (i, s, 10);

		return s;
	}


	constexpr auto to_number (String auto&& s) noexcept -> Number auto 
	requires requires () 
	{
		to_integer (s);
	}
	{
		return to_integer (s);
	}

	constexpr auto to_number (String auto&& s) noexcept -> Number auto 
	requires requires () 
	{
		to_double (s);
	}
	{
		return to_double (s);
	}

	constexpr auto to_number (String auto&& s) noexcept -> Number auto 
	requires requires () 
	{
		to_long_integer (s);
	}
	{
		return to_long_integer (s);
	}

constexpr auto to_integer (String auto&& s) noexcept -> Integer auto 
	{
		return atoi (c_string (s));;
	}

	constexpr auto to_double (String auto&& s) noexcept -> Floating auto 
	{
		return atof (c_string (s));;
	}

	constexpr auto to_long_integer (String auto&& s) noexcept -> Integer auto 
	{
		return atol (c_string (s));;
	}

}