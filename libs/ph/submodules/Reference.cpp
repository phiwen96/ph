export module Ph.Reference;

	template <typename T>
	struct reference 
	{
		constexpr static bool value = false;
	};

	template <typename T>
	struct reference <T&>
	{
		constexpr static bool value = true;
		using remove = T;
	};

	template <typename T>
	struct reference <T&&>
	{
		constexpr static bool value = true;
		using remove = T&;
	};

	template <typename T>
	struct reference <const T&>
	{
		constexpr static bool value = true;
	};

	template <typename T>
	struct creference 
	{
		constexpr static bool value = false;
	};

	template <typename T>
	struct creference <T const&>
	{
		constexpr static bool value = true;
		using remove = T;
	};

export namespace ph 
{
		template <typename T>
		concept Reference = reference <T>::value;

		template <Reference R>
		using remove_reference = typename reference <R>::remove;

		
		template <typename T>
		using remove_creference = typename creference <T>::remove;
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;

consteval auto Reference_test () -> bool
{
	using namespace ph;

	constexpr auto assert_reference = [] <Reference> {};
	constexpr auto assert_not_reference = [] <typename T> requires (not Reference <T>) {};

	testing::assert_all <int&, int&&, int*&, int*&&, int**&, int**&&> (assert_reference);
	testing::assert_all <int, int const, int*, int const*, int**> (assert_not_reference);

	return true;
}

static_assert (Reference_test ());

#endif