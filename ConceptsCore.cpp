export module Ph.Concepts.Core;


export import Ph.Dereferencable;
export import Ph.Concepts.Same_as;
export import Ph.Concepts.Not;
export import Ph.Concepts.Convertible_to;
export import Ph.Concepts.Bool;
export import Ph.Concepts.Void;
export import Ph.Concepts.Error;
export import Ph.Concepts.Done;
export import Ph.Concepts.Integer;
export import Ph.Concepts.Floating;

namespace ph 
{


export struct yes
{
	constexpr static bool value = true;
};

export struct no 
{
	constexpr static bool value = false;
};





template <typename T>
struct pointer_to_member : no {};

template <typename T, typename U>
struct pointer_to_member <T U::*> : yes {};

export template <typename... T>
concept Pointer_to_member = pointer_to_member <T...>::value;

struct Fun {
	auto fun () {}
};
static_assert (Pointer_to_member <decltype (&Fun::fun)>);










	







// module :private;



}