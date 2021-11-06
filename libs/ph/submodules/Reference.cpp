export module Ph.Concepts.Reference;

import Ph.Assert;

namespace ph 
{
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

	export 
	{
		template <typename T>
		concept Reference = reference <T>::value;

		template <Reference R>
		using remove_reference = typename reference <R>::remove;

		
		template <typename T>
		using remove_creference = typename creference <T>::remove;
	}
}





consteval auto Reference_test () -> bool
{
	using namespace ph;

	constexpr auto assert_reference = [] <Reference> {};
	constexpr auto assert_not_reference = [] <typename T> requires (not Reference <T>) {};



	return true;
}

static_assert (Reference_test ());
