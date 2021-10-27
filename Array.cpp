export module Ph.Concepts.Array;


import Ph.Concepts.Size;

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

	inline constexpr auto len (auto&& s) noexcept (s.size ()) -> Size auto 
	requires requires ()
	{
		{s.size ()} -> Size;
	}
	{
		return s.size ();
	}
	

	template <typename T>
	concept Array = requires (T t)
	{
		{size (t)} -> Size;
	};
}

// module :private;

import <array>;

consteval auto test ()
{
	Array auto a = {1, 2, 3};

	static_assert (Array <std::array <int, 3>>);
	static_assert (size (std::array {1, 2, 3}) == 3);

	return true;
}

static_assert (test ());





