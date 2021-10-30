export module Ph.Concepts.Function;

import Ph.Concepts.Core;

namespace ph 
{

template<class>
struct is_function : no {};
 
template<class Ret, class... Args>
struct is_function<Ret(Args...)> : yes {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile> : yes {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const> : yes {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile> : yes {};

template<class Ret, class... Args>
struct is_function<Ret(Args...) &> : yes {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const &> : yes {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile &> : yes {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile &> : yes {};

template<class Ret, class... Args>
struct is_function<Ret(Args...) &&> : yes {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const &&> : yes {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile &&> : yes {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile &&> : yes {};

template<class Ret, class... Args>
struct is_function<Ret(Args...) noexcept> : yes {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const noexcept> : yes {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile noexcept> : yes {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile noexcept> : yes {};

template<class Ret, class... Args>
struct is_function<Ret(Args...) & noexcept> : yes {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const & noexcept> : yes {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile & noexcept> : yes {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile & noexcept> : yes {};

template<class Ret, class... Args>
struct is_function<Ret(Args...) && noexcept> : yes {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const && noexcept> : yes {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile && noexcept> : yes {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile && noexcept> : yes {};



export template <typename T>
concept Function = is_function <T>::value;
        








auto fun_0 () 
{

}

auto fun_1 (int) 
{
	
}

auto fun_2 (int, char) 
{
	
}

struct Fun_3 
{	
	auto fun_3 (int, char) 
	{
	
	}
};


static_assert (Function <decltype (fun_0)>);
static_assert (Function <decltype (fun_1)>);
static_assert (Function <decltype (fun_2)>);
// static_assert (Function <decltype (Fun_3 {}.fun_3)>);

}