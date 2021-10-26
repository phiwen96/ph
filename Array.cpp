export module Ph.Concepts.Array;

import <type_traits>;
import <string>;

import Ph.Concepts.Size;
import Ph.Concepts.Char;

template <typename T>
struct array 
{

};

template <typename T, Size auto N>
struct array <T [N]>
{
	inline static constexpr auto len () noexcept -> Size auto
	{
		return N;
	}
};

template <typename T, Size auto N>
struct array <T (&) [N]>
{
	inline static constexpr auto len () noexcept -> Size auto
	{
		return N;
	}
};



export 
{
	inline constexpr auto len (auto&& s) noexcept -> Size auto 
	requires requires ()
	{
		{array <decltype (s)>::len ()} -> Size;
	}
	{
		return array <decltype (s)>::len ();
	}

	inline auto len (char const* s) -> Size auto 
	{
		return strlen (s);
	}

	template <typename T>
	concept Array = requires (T t)
	{
		{size (t)} -> Size;
	};
}

