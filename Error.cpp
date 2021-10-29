export module Ph.Concepts.Error;

import Ph.Concepts.Bool;
import Ph.Concepts.Void;

export 
{
	template <typename E>
	concept Error = requires (E const e)
	{
		{e.get_error ()} noexcept -> Bool;

	} and requires (E e)
	{
		{e.set_error (true)} noexcept -> Void;
	};



	struct error 
	{
		constexpr error () noexcept : _error {false}
		{

		}

		constexpr error (error&& other) noexcept : _error {other._error}
		{

		}

		constexpr error (error const& other) noexcept : _error {other._error}
		{

		}

		auto get_error () const noexcept -> Bool auto
		{
			return _error;
		}

		auto set_error (Bool auto&& b) noexcept -> Void auto
		{
			_error = b;
		}

		private:
		bool _error;
	};


}

static_assert (Error <error>);