


/**
 * 
 * TODO
 * 
 * implement a static string
 */



export module Ph.Concepts.String;



import Ph.Concepts.Void;
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

inline namespace string 
{

// static_assert (not Convertible_to <char const (&) [17], char const*>);

export 
{
	// using string = std::string;
	
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


	

	constexpr auto len (Array auto&& a) noexcept -> Size auto
	{
		return ph::array::len (a);
	}

	// constexpr auto len (auto const& s) noexcept -> Size auto 
	// requires requires () 
	// {
	// 	{s.size ()} noexcept -> Size;
	// }
	// {
	// 	return s.size ();
	// }

	constexpr auto len (auto const& s) noexcept -> Size auto 
	requires requires () 
	{
		{strlen (s)} -> Size;
		requires (not Array <decltype (s)>);
	}
	{
		return strlen (s);
	}

	template <typename A, typename B, typename... C>
	constexpr auto len (A const& a, B const& b, C const&... c)
	requires requires ()
	{
		{ph::string::len (a)} -> Size;
		{ph::string::len (b)} -> Size;
		// {ph::string::len (c)} -> Size;
	}
	{
		return (ph::string::len (a) + ph::string::len (a));
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




	constexpr auto append (String auto&& s0, String auto&& s1, String auto&&... sR) noexcept -> String auto
	{
		Number auto length = len (s0, s1, sR...);

		

		String auto c_s1 = (char*) malloc (sizeof (char) * length);

		strcpy (c_s1, ph::string::c_string (s0));
		strcat (c_s1, ph::string::c_string (s1));
		// memcpy (c_s1, ph::string::c_string (s0), sizeof (char) * ph::string::len (s0));
		// memcpy (c_s1 + ph::string::len (s0), ph::string::c_string (s1), sizeof (char) * ph::string::len (s1));
	


		if constexpr (sizeof... (sR) > 0)
		{
			return ph::string::append (c_s1, sR...);

		} else 
		{
			return c_s1;
		}
	}

}


// bool test ()
// {
// 	ph::String auto s1 = "hello";
// 	ph::String auto s2 = " there.";

// 	ph::String auto s3 = ph::string::append (s1, s2);
// 	return true;
// }

}



}


// assert (ph::string::test ());
static_assert (ph::String <char const (&)[17]>);
static_assert (ph::String <char const*>);
static_assert (ph::String <std::string>);