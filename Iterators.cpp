export module Concepts.Iterators;

import <type_traits>;

template <typename T>
concept Const = std::is_const_v <T>;

template <typename T>
concept Ref = std::is_reference_v <T>;



export 
{
	template <typename T>
	concept Input_iterator = requires (T& t)
	{
		{*t} -> Const;
		t++;
		++t;
	};

	template <typename T>
	concept Output_iterator = requires (T& t)
	{
		{*t} -> Ref;
		t++;
		++t;
	};
}