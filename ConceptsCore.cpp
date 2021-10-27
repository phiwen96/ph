export module Ph.Concepts.Core;

import <type_traits>;


export import Ph.Convertible_to;



export 
{
	template <typename T>
	concept Const = std::is_const_v <std::remove_reference_t <T>>;

	template <typename T>
	concept Ref = std::is_reference_v <T>;
	
	template <typename T>
	concept Ptr = std::is_pointer_v <T>;
}

export import Ph.Dereferencable;
export import Ph.Same_as;






module :private;

static_assert (not Const <int>);
static_assert (Const <int const>);
static_assert (Const <int const&>);

static_assert (not Ref <int>);
static_assert (Ref <int const&>);
static_assert (Ref <int&>);
static_assert (Ref <int&&>);

static_assert (not Ptr <int>);
static_assert (Ptr <int*>);
static_assert (Ptr <int**>);