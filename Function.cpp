export module Ph.Concepts.Function;

import Ph.Concepts.Convertible_to;
import std;
namespace ph 
{

template<class>
struct is_function : std::false_type {};
 
template<class Ret, class... Args>
struct is_function<Ret(Args...)> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile> : std::true_type {};

template<class Ret, class... Args>
struct is_function<Ret(Args...) &> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const &> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile &> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile &> : std::true_type {};

template<class Ret, class... Args>
struct is_function<Ret(Args...) &&> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const &&> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile &&> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile &&> : std::true_type {};

template<class Ret, class... Args>
struct is_function<Ret(Args...) noexcept> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const noexcept> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile noexcept> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile noexcept> : std::true_type {};

template<class Ret, class... Args>
struct is_function<Ret(Args...) & noexcept> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const & noexcept> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile & noexcept> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile & noexcept> : std::true_type {};

template<class Ret, class... Args>
struct is_function<Ret(Args...) && noexcept> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const && noexcept> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile && noexcept> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile && noexcept> : std::true_type {};



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