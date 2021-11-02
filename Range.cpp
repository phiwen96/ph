export module Ph.Concepts.Range;

import Ph.Concepts.Reference;
import Ph.Concepts.Bool;
import Ph.Concepts.Constant;
import Ph.Concepts.Size;
import Ph.Concepts.Element;
import Ph.Concepts.Pointer;

import std;



namespace ph 
{
	template <typename T>
	struct contains_proxy { T const& _value; };

	consteval auto rangeable (auto&& r) -> Bool auto 
	{
		return true;
	}

	export 
	{



		template <typename R>
		concept Range = requires (R r)
		{
			// if (true) {};
			true;
			// requires (rangeable (r) == true);

			// {ph::begin (r)} noexcept -> Iterator;
			// {ph::end (r)} noexcept -> Iterator;
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

		template <Pointer P>
		struct range_t 
		{
			constexpr range_t (P b, P e) noexcept : _begin {b}, _end {e}
			{

			}
		private:
			P _begin;
			P _end;
		};
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