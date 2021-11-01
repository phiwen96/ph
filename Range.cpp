export module Ph.Concepts.Range;

import Ph.Concepts.Reference;
import Ph.Concepts.Bool;
import Ph.Concepts.Iterator;
import Ph.Concepts.Constant;
import Ph.Concepts.Size;
import Ph.Concepts.Element;

import std;



namespace ph 
{
	template <typename T>
	struct contains_proxy { T const& _value; };



	export 
	{
		template <typename R>
		concept Range = requires (R r)
		{
			{ph::begin (r)} noexcept -> Iterator;
			{ph::end (r)} noexcept -> Iterator;
		};

		template <typename E>
		constexpr auto contains (E const& e) noexcept -> auto
		{
			return contains_proxy <E> {e};
		}

		template <typename E>
		constexpr auto operator | (Range auto const& r, contains_proxy <E> const& proxy) noexcept -> Bool auto
		{
			auto const& v = proxy._value;
			for (auto const& e : r)
			{
				if (e == proxy._value) return true;
			}

			return false;
		}
	}


	static_assert (Range <std::vector <int>>);
	static_assert (Range <std::array <int, 10>>);


	consteval auto test () noexcept -> Bool auto 
	{
		Bool auto b = true;
		 

		return b;
	}

	static_assert (test ());
}