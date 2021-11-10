export module Ph.Pointer;

	template <typename T>
	struct pointer_traits
	{
		static constexpr bool value = false;
	};

	template <typename T>
	struct pointer_traits <T*> 
	{
		static constexpr bool value = true;
		using element = T;
	};

	template <typename T>
	struct pointer_traits <T*&> 
	{
		static constexpr bool value = true;
		using element = T;
	};

	template <typename T>
	struct pointer_traits <T*&&> 
	{
		static constexpr bool value = true;
		using element = T;
	};

	template <typename T>
	struct pointer_traits <T**> 
	{
		static constexpr bool value = true;
		using element = T;
	};

	template <typename T>
	struct pointer_traits <T**&> 
	{
		static constexpr bool value = true;
		using element = T;
	};

	template <typename T>
	struct pointer_traits <T**&&> 
	{
		static constexpr bool value = true;
		using element = T;
	};

export namespace ph 
{	
	template <typename T>
	concept Pointer = pointer_traits <T>::value;

	template <Pointer P>
	using remove_pointer = typename pointer_traits <P>::element;
}

/*==================================
 TESTING
====================================*/
#ifdef Testing

// using namespace ph;

import Ph.Test;



consteval bool Pointer_test ()
{
	

	constexpr auto assert_pointer = [] <ph::Pointer> {};
	constexpr auto assert_not_pointer = [] <typename T> () requires (not ph::Pointer <T>) {};

	testing::assert_all <int*, int*&, int*&&, int const*, int**, int**&, int**&&> (assert_pointer);
	testing::assert_all <int, int&, int&&> (assert_not_pointer);

	return true;
}

static_assert (Pointer_test ());

#endif