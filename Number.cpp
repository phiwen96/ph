export module Concepts.Numbers.Number;

export import Concepts.Numbers.Signed;
export import Concepts.Numbers.Unsigned;

export 
{
	template <typename T>
	concept Number = Signed <T> or Unsigned <T>;
}