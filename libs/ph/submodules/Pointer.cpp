export module Ph.Concepts.Memory.Pointer;

import Ph.Assert;

namespace ph 
{

	template <typename T>
	struct pointer
	{
		static constexpr bool value = false;
	};

	template <typename T>
	struct pointer <T*> 
	{
		static constexpr bool value = true;
	};

	template <typename T>
	struct pointer <T**> 
	{
		static constexpr bool value = true;
	};



	export 
	{
		template <typename T>
		concept Pointer = pointer <T>::value;
	}


}









consteval bool Pointer_test ()
{
	using namespace ph;
	constexpr auto assert_pointer = [] <Pointer> {};
	constexpr auto assert_not_pointer = [] <typename T> () requires (not Pointer <T>) {};
	assert_all <int*, int**> (assert_pointer);
	assert_all <int, int&> (assert_not_pointer);

	return true;
}

static_assert (Pointer_test ());