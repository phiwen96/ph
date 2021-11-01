export module Ph.Concepts.Range;

import Ph.Concepts.Reference;
import Ph.Concepts.Bool;
import Ph.Concepts.Iterator;
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

		template <typename Element>
		constexpr auto contains (Element const& e) noexcept -> auto
		{
			return contains_proxy <Element> {e};
		}

		template <typename Element>
		constexpr auto operator | (Range auto const& r, contains_proxy <Element> const& proxy) noexcept -> Bool auto
		{
			auto const& v = proxy._value;
			for (auto const& e : r)
			{
				if (e == proxy._value) return true;
			}

			return false;
		}
	}
}