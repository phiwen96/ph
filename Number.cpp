export module Ph.Number;

export import Ph.Number.Signed;
export import Ph.Number.Unsigned;
export import Ph.Number.Integer;
export import Ph.Number.Float;

namespace ph 
{

export 
{
	template <typename T>
	concept Number = Signed <T> or Unsigned <T>;
}
}