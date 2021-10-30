export module Ph.Concepts.Array;


import Ph.Concepts.Size;
import Ph.Concepts.Pointer;

import std;

namespace ph 
{

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

	inline static constexpr auto data (T const& t) noexcept -> Pointer auto
	requires requires (T t) 
	{
		{t.data ()} -> Pointer;
	}
	{
		return t.data ();
	}
};

template <typename T, Size auto N>
struct array <std::array <T, N>>
{
	inline static constexpr auto len () noexcept -> Size auto
	{
		return N;
	}

	inline static constexpr auto data (std::array <T, N> const& a) noexcept -> Pointer auto
	{
		return a.data ();
	}
};

template <typename T, Size auto N>
struct array <T [N]>
{
	inline static constexpr auto len () noexcept -> Size auto
	{
		return N;
	}

	inline static constexpr auto data (T const (&a) [N]) noexcept -> Pointer auto
	{
		return &a;
	}
};



template <typename T, Size auto N>
struct array <T (&) [N]>
{
	inline static constexpr auto len () noexcept -> Size auto
	{
		return N;
	}

	inline static constexpr auto data (T (&a) [N]) noexcept -> Pointer auto
	{
		return static_cast <T*> (a);
	}
};

template <typename T, Size auto N>
struct array <T const (&) [N]>
{
	inline static constexpr auto len () noexcept -> Size auto
	{
		return N;
	}

	inline static constexpr auto data (T const (&a) [N]) noexcept -> Pointer auto
	{
		return static_cast <T*> (a);
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

	inline auto data (Array auto&& a) -> Pointer auto
	{
		return array <decltype (a)>::data (a);
	}
}

}

import std;

consteval auto test ()
{
	ph::Array auto a = {1, 2, 3};

	static_assert (ph::Array <std::array <int, 3>>);
	static_assert (ph::len (std::array {1, 2, 3}) == 3);

	return true;
}

static_assert (test ());






