export module Ph.Concepts.Function;

// export import <type_traits>;

import Ph.Concepts.Core;

// primary template
template<class>
struct is_function : no { };
 
// specialization for regular functions
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
        