


/**
 * 
 * TODO
 * 
 * implement a static string
 */



export module Ph.Concepts.String;




import Ph.Concepts.Convertible_to;
import Ph.Concepts.Integer;
import Ph.Concepts.Floating;
import Ph.Concepts.Char;
import Ph.Concepts.Size;
import Ph.Concepts.Array;
import Ph.Concepts.Numbers;

export import std;

namespace ph
{



// static_assert (not Convertible_to <char const (&) [17], char const*>);


export 
{
	using string = std::string;
	
	constexpr auto c_string (char const* a) noexcept -> char const*
	{
		return a;
	}

	constexpr auto c_string (Array auto && a) noexcept -> char const*
	{
		return ph::data (a);
	}

	// constexpr auto c_string (auto&& s) noexcept -> char const* requires requires () {
	// 	{s.c_str ()} -> Convertible_to <char const*>;
	// 	// requires (not Array <decltype (s)>);
	// }
	// {
	// 	return s.c_str ();
	// }


	

	// constexpr auto len (Array auto&& a) noexcept -> Size auto
	// {
	// 	return len (a);
	// }

	constexpr auto len (auto&& s) noexcept -> Size auto requires requires () {
		{strlen (s)} -> Size;
		requires (not Array <decltype (s)>);
	}
	{
		return strlen (s);
	}

	template <typename T>
	concept String = requires (T t)
	{
		c_string (t);
		len (t);
	};

	auto to_string (Integer auto&& i) noexcept -> String auto
	requires requires () 
	{
		std::to_string (i);
	} 
	{
		std::string s = std::to_string (i);
		char* r = (char*) std::malloc (sizeof (char) * len (s));
		std::strcpy (r, s.data ());
		return static_cast <char const*> (r);
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


}












static_assert (ph::String <char const (&)[17]>);
static_assert (ph::String <char const*>);
static_assert (ph::String <std::string>);