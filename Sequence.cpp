export module Ph.Concepts.Sequence;

import Ph.Concepts.Core;
// import Ph.


template <typename T>
concept Sequence = requires (T& t)
{
	{begin (t)} -> Dereferencable;
	{end (t)} -> Dereferencable;
};

