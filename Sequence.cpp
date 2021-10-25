export module Concepts.Sequence;

import Concepts.Core;



template <typename T>
concept Sequence = requires (T& t)
{
	begin (t);
	end (t);
};

