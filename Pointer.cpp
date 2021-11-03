export module Ph.Concepts.Memory.Pointer;


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

using namespace ph;

consteval bool Pointer_test ()
{

	return true;
}

static_assert (Pointer_test ());