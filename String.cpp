export module Ph.Concepts.String;

// import <iostream>;
import <string>;
import Ph.Concepts.Core;
import Ph.Concepts.Char;
import Ph.Concepts.Size;


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
		{s.size ()} -> Size;
	}
	{
		return s.size ();
	}

	auto len (char const* s) -> Size auto 
	{
		return strlen (s);
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



module :private;

static_assert (String <std::string>);
