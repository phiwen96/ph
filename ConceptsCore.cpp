export module Ph.Concepts.Core;






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



export template <typename T>
concept Const = not requires (T t0, T t1)
{
	t0 = t1;
};





template <typename>
struct ref : no {};

template <typename T>
struct ref <T&> : yes {};

template <typename T>
struct ref <T&&> : yes {};

export template <typename T>
concept Ref = ref <T>::value;








	
template <typename>
struct ptr : no {};

template <typename T>
struct ptr <T*> : yes {};

template <typename T>
struct ptr <T**> : yes {};

export template <typename T>
concept Ptr = ptr <T>::value;



export import Ph.Dereferencable;
export import Ph.Concepts.Same_as;
export import Ph.Concepts.Not;
export import Ph.Concepts.Convertible_to;
export import Ph.Concepts.Bool;
export import Ph.Concepts.Void;
export import Ph.Concepts.Error;
export import Ph.Concepts.Done;
export import Ph.Concepts.Integer;






// module :private;

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
