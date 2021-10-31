export module Ph.Concepts.Common;

import std;

namespace ph 
	{
		// primary template (used for zero types)
	template<class...>
	struct _common {};
	
	//////// one type
	template <class T>
	struct _common<T> : _common<T, T> {};
	
	namespace detail {
	template<class...>
	using void_t = void;
	
	template<class T1, class T2>
	using conditional_result_t = decltype(false ? std::declval<T1>() : std::declval<T2>());
	
	template<class, class, class = void>
	struct decay_conditional_result {};
	template<class T1, class T2>
	struct decay_conditional_result<T1, T2, void_t<conditional_result_t<T1, T2>>>
		: std::decay<conditional_result_t<T1, T2>> {};
	
	template<class T1, class T2, class = void>
	struct _common_2_impl : decay_conditional_result<const T1&, const T2&> {};
	
	// C++11 implementation:
	// template<class, class, class = void>
	// struct _common_2_impl {};
	
	template<class T1, class T2>
	struct _common_2_impl<T1, T2, void_t<conditional_result_t<T1, T2>>>
		: decay_conditional_result<T1, T2> {};
	}
	
	//////// two types
	template<class T1, class T2>
	struct _common<T1, T2> 
		: std::conditional<std::is_same<T1, typename std::decay<T1>::type>::value &&
						std::is_same<T2, typename std::decay<T2>::type>::value,
						detail::_common_2_impl<T1, T2>,
						_common<typename std::decay<T2>::type,
									typename std::decay<T2>::type>>::type {};
	
	//////// 3+ types
	namespace detail {
	template<class AlwaysVoid, class T1, class T2, class...R>
	struct _common_multi_impl {};
	template<class T1, class T2, class...R>
	struct _common_multi_impl<void_t<typename _common<T1, T2>::type>, T1, T2, R...>
		: _common<typename _common<T1, T2>::type, R...> {};
	}
	
	template<class T1, class T2, class... R>
	struct _common<T1, T2, R...>
		: detail::_common_multi_impl<void, T1, T2, R...> {};
		
		export 
		{
			template <typename... T>
			using common = typename _common <T...>::type;

			template <typename... T>
			concept Common = requires ()
			{
				_common <T...>::type;
			};
		}
	}

