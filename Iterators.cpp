export module Concepts.Iterators;

import Concepts.Core;





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