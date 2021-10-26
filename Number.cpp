export module Ph.Concepts.Numbers.Number;

export import Ph.Concepts.Numbers.Signed;
export import Ph.Concepts.Numbers.Unsigned;

export 
{
	template <typename T>
	concept Number = Signed <T> or Unsigned <T>;
}