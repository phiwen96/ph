export module Ph.Concepts.Error;

import Ph.Concepts.Bool;
import Ph.Concepts.Void;
import std;
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
		constexpr _error (Bool auto&& b) noexcept : __error {b}
		{
			// std::cout << __error << std::endl;
		}

		constexpr _error () noexcept : __error {false}
		{
			// std::cout << __error << std::endl;
		}

		constexpr _error (_error&& other) noexcept : __error {(bool&&) other.__error}
		{
			// std::cout << __error << std::endl;
		}

		constexpr _error (_error const& other) noexcept : __error {(bool const&) other.__error}
		{
			// std::cout << __error << std::endl;
		}

		auto get_error () const noexcept -> Bool auto
		{
			return __error;
		}

		auto set_error (Bool auto&& b, char const* f = __builtin_FILE (), int line = __builtin_LINE ()) noexcept -> Void auto
		{
			if (b)
			{
				_file = (char*) malloc (sizeof (char) * strlen (f));
				strcpy (_file, f);
				_line = line;
			}
			// std::cout << "setting error" << std::endl;
			__error = b;
		}

		constexpr operator Error auto () const noexcept 
		{
			// std::cout << __error << std::endl;
			
			return __error;
		}

		private:
		bool __error;
		char* _file;
		int _line;
	};




}

static_assert (Error <_error>);
}