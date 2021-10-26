export module Ph;


export import Ph.Core;
export import Ph.Concepts;
export import Ph.Network;

import <string>;

export 
{


	template <typename T>
	constexpr auto to_string (std::string&& s) noexcept -> char const*
	requires (Same_as <T, char const*>)
	{
		return s.c_str ();
	}

	template <typename T>
	inline constexpr auto to_string (auto&& s) noexcept -> char const*
	{
		if constexpr (Same_as <Tchar const*>)
		{
			return s;

		} else if constexpr (Same_as <std::string>)
		{
			return s.c_str ();
		}
	}
}