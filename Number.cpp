export module concepts.Number;

export import concepts.Number.Signed;
export import concepts.Number.Unsigned;

export {
template <typename T>
concept Number = Signed <T> or Unsigned <T>;
}