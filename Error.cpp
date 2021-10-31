export module Ph.Concepts.Error;

import Ph.Concepts.Bool;
import Ph.Concepts.Void;

namespace ph 
{

export 
{
	template <typename E>
	concept Error = Bool <E> or requires (E e)
	{
		{e.get_error ()} noexcept -> Bool;
		{e.set_error (true)} noexcept -> Void;
	};

	auto error (Error auto&& e) noexcept -> Error auto 
	requires requires ()
	{
		{e.get_error ()} noexcept -> Bool;
	}
	{
		return e.get_error ();
	}

	auto error (Bool auto&& b) noexcept -> Error auto 
	{
		return b;
	}



	struct _error 
	{
		constexpr _error () noexcept : __error {false}
		{

		}

		constexpr _error (_error&& other) noexcept : __error {other.__error}
		{

		}

		constexpr _error (_error const& other) noexcept : __error {other.__error}
		{

		}

		auto get_error () const noexcept -> Bool auto
		{
			return __error;
		}

		auto set_error (Bool auto&& b) noexcept -> Void auto
		{
			__error = b;
		}

		private:
		bool __error;
	};




}

static_assert (Error <_error>);
}