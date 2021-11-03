export module Ph.Concepts.Number;

export import Ph.Concepts.Number.Signed;
export import Ph.Concepts.Number.Unsigned;
export import Ph.Concepts.Number.Integer;
export import Ph.Concepts.Number.Float;

namespace ph 
{

export 
{
	template <typename T>
	concept Number = Signed <T> or Unsigned <T>;
}
}