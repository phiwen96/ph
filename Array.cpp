export module Ph.Concepts.Array;


import Ph.Concepts.Size;
import std;

template <typename T>
struct array 
{
	inline static constexpr auto len (T const& t) noexcept -> Size auto
	requires requires (T t) 
	{
		{t.size ()} -> Size;
	}
	{
		return t.size ();
	}
};

template <typename T, Size auto N>
struct array <std::array <T, N>>
{
	inline static constexpr auto len () noexcept -> Size auto
	{
		return N;
	}
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
	
	inline constexpr auto len (auto&& s) noexcept -> Size auto 
	requires requires ()
	{
		{array <decltype (s)>::len (s)} -> Size;
	}
	{
		return array <decltype (s)>::len (s);
	}

	template <typename T>
	concept Array = requires (T t)
	{
		{len (t)} -> Size;
	};
}

// module :private;

import std;

consteval auto test ()
{
	Array auto a = {1, 2, 3};

	static_assert (Array <std::array <int, 3>>);
	static_assert (size (std::array {1, 2, 3}) == 3);

	return true;
}

static_assert (test ());





