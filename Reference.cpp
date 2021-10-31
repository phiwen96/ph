export module Ph.Concepts.Reference;

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

	export 
	{
		template <typename T>
		concept Reference = reference <T>::value;

		template <typename T>
		using remove_reference = typename reference <T>::remove;
	}
}