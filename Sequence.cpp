export module Ph.Concepts.Sequence;

import Ph.Core;



template <typename T>
concept Sequence = requires (T& t)
{
	begin (t);
	end (t);
};

