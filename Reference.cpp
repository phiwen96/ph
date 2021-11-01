export module Ph.Concepts.Reference;

import Ph.Concepts.Same_as;

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

		template <typename T>
		using remove_reference = typename reference <T>::remove;

		
		template <typename T>
		using remove_creference = typename creference <T>::remove;
	}
}

static_assert (ph::Same_as <ph::remove_reference <int&>, int>);