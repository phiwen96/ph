export module Ph.Assert;


namespace ph 
{
	template <auto boolfunction, typename...>
	struct assert_all_t;

	template <auto boolfunction, typename T, typename... U>
	struct assert_all_t <boolfunction, T, U...>
	{
		constexpr static bool value = boolfunction.template operator () <T> () and assert_all_t <boolfunction, U...>::value;
	};

	template <auto boolfunction, typename T>
	struct assert_all_t <boolfunction, T>
	{
		constexpr static bool value = boolfunction.template operator () <T> ();
	};

	constexpr auto _assert_true = [] (auto&& b) constexpr noexcept -> bool 
	requires requires ()
	{
		b == true;
	}
	{
		return b == true;
	};

	export 
	{
		
		consteval auto assert_true (auto&&... b)
		requires requires ()
		{
			requires ((b == true) and ...);
		}
		{

		}

		template <typename... T>
		consteval inline auto assert_all (auto&& lambda) noexcept -> void
		requires requires ()
		{
			((lambda.template operator () <T> ()), ...);
		}
		{

		}
		
		template <typename... T>
		consteval inline auto assert_all (auto&& lambda, auto&&... lambdas) noexcept -> void 
		requires requires ()
		{
			((lambda.template operator () <T> ()), ...);
			assert_all <T...> (lambdas...);
		}
		{

		}





		template <typename... T>
		consteval inline auto assert_not_all (auto&& lambda) noexcept -> void
		requires requires ()
		{
			
			requires not requires ()
			{
				((lambda.template operator () <T> ()), ...);
			};
		}
		{

		}
		
		template <typename... T>
		consteval inline auto assert_not_all (auto&& lambda, auto&&... lambdas) noexcept -> void
		requires requires ()
		{
			requires not requires ()
			{
				((lambda.template operator () <T> ()), ...);
			};

			assert_not_all <T...> (lambdas...);
		}
		{

		}


	}
}


using namespace ph;

struct assert_test 
{
	auto open () 
	{

	}
};

consteval auto Assert_test () -> bool
{
	// assert_true (true, true, true);

	constexpr auto assert_bool = [] <bool> () constexpr noexcept {};
	// static_assert (Convertible_to <char*, bool>);
	// assert_all <int, bool, char*> (assert_bool); 
	constexpr auto assert_no_open = [] <typename T> () constexpr noexcept 
	requires requires (T t)
	{
		requires not requires ()
		{
			t.open ();
		};
	}
	{};

	assert_no_open.template operator () <int> ();
	

	struct _A {};      assert_not_all <_A, int> (assert_bool); // should generate error




	// assert_all <string_check, int> ();
	// assert_all <int> ([] <typename T> {return Same_as <char, T>;});
	return true;
}


static_assert (Assert_test ());
