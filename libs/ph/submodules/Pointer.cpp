export module Ph.Pointer;

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
	struct pointer <T*&> 
	{
		static constexpr bool value = true;
	};

	template <typename T>
	struct pointer <T*&&> 
	{
		static constexpr bool value = true;
	};

	template <typename T>
	struct pointer <T**> 
	{
		static constexpr bool value = true;
	};

	template <typename T>
	struct pointer <T**&> 
	{
		static constexpr bool value = true;
	};

	template <typename T>
	struct pointer <T**&&> 
	{
		static constexpr bool value = true;
	};

export namespace ph 
{
	template <typename T>
	concept Pointer = pointer <T>::value;
	
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;

consteval bool Pointer_test ()
{
	using namespace ph;

	constexpr auto assert_pointer = [] <Pointer> {};
	constexpr auto assert_not_pointer = [] <typename T> () requires (not Pointer <T>) {};

	test::assert_all <int*, int*&, int*&&, int const*, int**, int**&, int**&&> (assert_pointer);
	test::assert_all <int, int&, int&&> (assert_not_pointer);

	return true;
}

static_assert (Pointer_test ());

#endif