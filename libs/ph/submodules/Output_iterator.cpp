export module Ph.Iterator.Output;

import Ph.Incrementable;
import Ph.Dereferenceable;
import Ph.Nothing;


namespace ph 
{
	export template <typename T>
	concept Output_iterator = Incrementable <T> and Dereferenceable <T>;

	namespace type 
	{
		template <typename T>
		struct element_of_t
		{
			constexpr static bool value = false;
		};

		template <Output_iterator O>
		struct element_of_t <O>
		{
			constexpr static bool value = true;

			using type = type::derefer <O>;
		};

		export template <Output_iterator O>
		using element_of = typename element_of_t <O>::type;
	}



	/*==================================
 	 FUNCTION DEFINITIONS
	====================================*/
	template <Output_iterator O, typename E>
	constexpr auto write (O && o, type::element_of <O> && e) noexcept -> Nothing auto
	requires requires () 
	{
		derefer (o) = e;
	}
	{
		derefer (o) = e;
	}

	constexpr auto next (Output_iterator auto&& o) noexcept -> Output_iterator auto
	{
		return ++o;
	}
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;
import std;

consteval auto Output_iterator_test () noexcept -> bool
{
	using namespace ph;
	
	constexpr auto assert_output_iterator = [] <Output_iterator> {};
	constexpr auto assert_not_output_iterator = [] <typename T> requires (not Output_iterator <T>) {};

	static_assert (Output_iterator <char*>);
	static_assert (Output_iterator <std::istream_iterator <int>>);
	static_assert (Output_iterator <std::ostream_iterator <int>>);
	// testing::assert_all <std::ostream_iterator> (assert_output_iterator);


	return true;
}

static_assert (Output_iterator_test ());

#endif

/*==================================
 FUNCTION IMPLEMENTATIONS
====================================*/
// namespace ph 
// {
	
// }