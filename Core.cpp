export module Concepts.Core;

// import <type_traits>;


export 
{
	template <typename T>
	concept Const = true;//std::is_const_v <std::remove_reference_t <T>>;

	template <typename T>
	concept Ref = true;//std::is_reference_v <T>;
	
	template <typename T>
	concept Ptr = true;//std::is_pointer_v <T>;
}





module :private;

static_assert (Const <int const>);
static_assert (Const <int const&>);

static_assert (Ref <int const&>);
static_assert (Ref <int&>);
static_assert (Ref <int&&>);

static_assert (Ptr <int*>);
static_assert (Ptr <int**>);
