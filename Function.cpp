export module Ph.Concepts.Function;

import Ph.Concepts.Convertible_to;
import Ph.Concepts.Same_as;
import Ph.Concepts.Types.List;
import Ph.Assert;

import std;
namespace ph 
{

template<class>
struct function_t : std::false_type 
{
	
};

 
template<class Ret, class... Args>
struct function_t<Ret(Args...)> : std::true_type 
{
	template <template <typename...> typename Into>
	using args = Into <Args...>;
};

template<class Ret, class... Args>
struct function_t<Ret(Args...) const volatile> : std::true_type 
{
	template <template <typename...> typename Into>
	using args = Into <Args...>;
};

template<class Ret, class... Args>
struct function_t<Ret(Args...) const> : std::true_type 
{
	template <template <typename...> typename Into>
	using args = Into <Args...>;
};

template<class Ret, class... Args>
struct function_t<Ret(Args...) volatile> : std::true_type 
{
	template <template <typename...> typename Into>
	using args = Into <Args...>;
};


template<class Ret, class... Args>
struct function_t<Ret(Args...) &> : std::true_type 
{
	template <template <typename...> typename Into>
	using args = Into <Args...>;
};

template<class Ret, class... Args>
struct function_t<Ret(Args...) const &> : std::true_type 
{
	template <template <typename...> typename Into>
	using args = Into <Args...>;
};

template<class Ret, class... Args>
struct function_t<Ret(Args...) volatile &> : std::true_type 
{
	template <template <typename...> typename Into>
	using args = Into <Args...>;
};

template<class Ret, class... Args>
struct function_t<Ret(Args...) const volatile &> : std::true_type 
{
	template <template <typename...> typename Into>
	using args = Into <Args...>;
};


template<class Ret, class... Args>
struct function_t<Ret(Args...) &&> : std::true_type 
{
	template <template <typename...> typename Into>
	using args = Into <Args...>;
};

template<class Ret, class... Args>
struct function_t<Ret(Args...) const &&> : std::true_type 
{
	template <template <typename...> typename Into>
	using args = Into <Args...>;
};

template<class Ret, class... Args>
struct function_t<Ret(Args...) volatile &&> : std::true_type 
{
	template <template <typename...> typename Into>
	using args = Into <Args...>;
};

template<class Ret, class... Args>
struct function_t<Ret(Args...) const volatile &&> : std::true_type 
{
	template <template <typename...> typename Into>
	using args = Into <Args...>;
};


template<class Ret, class... Args>
struct function_t<Ret(Args...) noexcept> : std::true_type 
{
	template <template <typename...> typename Into>
	using args = Into <Args...>;
};

template<class Ret, class... Args>
struct function_t<Ret(Args...) const noexcept> : std::true_type 
{
	template <template <typename...> typename Into>
	using args = Into <Args...>;
};

template<class Ret, class... Args>
struct function_t<Ret(Args...) volatile noexcept> : std::true_type 
{
	template <template <typename...> typename Into>
	using args = Into <Args...>;
};

template<class Ret, class... Args>
struct function_t<Ret(Args...) const volatile noexcept> : std::true_type 
{
	template <template <typename...> typename Into>
	using args = Into <Args...>;
};


template<class Ret, class... Args>
struct function_t<Ret(Args...) & noexcept> : std::true_type 
{
	template <template <typename...> typename Into>
	using args = Into <Args...>;
};

template<class Ret, class... Args>
struct function_t<Ret(Args...) const & noexcept> : std::true_type 
{
	template <template <typename...> typename Into>
	using args = Into <Args...>;
};

template<class Ret, class... Args>
struct function_t<Ret(Args...) volatile & noexcept> : std::true_type 
{
	template <template <typename...> typename Into>
	using args = Into <Args...>;
};

template<class Ret, class... Args>
struct function_t<Ret(Args...) const volatile & noexcept> : std::true_type 
{
	template <template <typename...> typename Into>
	using args = Into <Args...>;
};


template<class Ret, class... Args>
struct function_t<Ret(Args...) && noexcept> : std::true_type 
{
	template <template <typename...> typename Into>
	using args = Into <Args...>;
};

template<class Ret, class... Args>
struct function_t<Ret(Args...) const && noexcept> : std::true_type 
{
	template <template <typename...> typename Into>
	using args = Into <Args...>;
};

template<class Ret, class... Args>
struct function_t<Ret(Args...) volatile && noexcept> : std::true_type 
{
	template <template <typename...> typename Into>
	using args = Into <Args...>;
};

template<class Ret, class... Args>
struct function_t<Ret(Args...) const volatile && noexcept> : std::true_type 
{
	template <template <typename...> typename Into>
	using args = Into <Args...>;
};



export 
{
	template <typename T>
	concept Function = function_t <T>::value;

	template <Function F, template <typename...> typename Metafunction>
	using args =  typename function_t <F>::template args <Metafunction>;
}

        





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


}



consteval bool Function_test ()
{
	using namespace ph;

	constexpr auto assert_function = [] <Function> {};

	return true;
}

static_assert (Function_test ());