export module Ph.Concepts.Number;

export import Ph.Concepts.Number.Signed;
export import Ph.Concepts.Number.Unsigned;

namespace ph 
{

export 
{
	template <typename T>
	concept Number = Signed <T> or Unsigned <T>;
}
}