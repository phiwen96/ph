export module Ph.Iterator.Output;
import Ph.Reference;
import Ph.Iterator.Traits;


export namespace ph 
{
	template <typename T>
	concept Output_iterator = requires (T t1, T t2)
	{
		{*t1} -> Reference;
		t1++;
		++t1;
	};

	/*==================================
 	 FUNCTION DEFINITIONS
	====================================*/
	constexpr auto write (Output_iterator auto) noexcept -> Reference auto;
	constexpr auto next (Output_iterator auto) noexcept -> Output_iterator auto;
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
namespace ph 
{

	constexpr auto write (Output_iterator auto) noexcept -> Reference auto
	{
		
	}

	constexpr auto next (Output_iterator auto) noexcept -> Output_iterator auto
	{

	}
}