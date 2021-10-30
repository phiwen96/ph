export module Ph.Concepts.Sequence;

import Ph.Concepts.Core;


namespace ph 
{


template <typename T>
concept Sequence = requires (T& t)
{
	{begin (t)} -> Dereferencable;
	{end (t)} -> Dereferencable;
};


}