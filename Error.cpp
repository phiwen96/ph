export module Ph.Concepts.Error;

import Ph.Concepts.Convertible_to;
import Ph.Concepts.Bool;
import Ph.Concepts.Void;
import std;
import Ph.Color;
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

	// auto error (Error auto&& e) noexcept -> Error auto 
	// requires requires ()
	// {
	// 	{e.get_error ()} noexcept -> Bool;
	// }
	// {
	// 	return e.get_error ();
	// }

	// auto error (Bool auto&& b) noexcept -> Error auto 
	// {
	// 	return b;
	// }



	struct _error 
	{
		constexpr _error (Bool auto&& b) noexcept : __error {b}, _file {nullptr}
		{
			// std::cout << __error << std::endl;
		}

		constexpr _error () noexcept : __error {false}, _file {nullptr}
		{
			// std::cout << __error << std::endl;
		}

		constexpr _error (_error&& other) noexcept : __error {(bool&&) other.__error}, _file (other._file), _line (other._line)
		{
			// std::cout << __error << std::endl;
		}

		constexpr _error (_error const& other) noexcept : __error {(bool const&) other.__error}, _file (other._file), _line (other._line)
		{
			// std::cout << __error << std::endl;
		}

		constexpr auto get_error () const noexcept -> Bool auto
		{
			return __error;
		}

		constexpr _error& operator= (_error const& rhs) noexcept
		{
			__error = rhs.__error;
			_line = rhs._line;

			if (rhs._file != nullptr)
			{
				_file = (char*) malloc (sizeof (char) * strlen (rhs._file));
				strcpy (_file, rhs._file);
			}

			return *this;
		}

		constexpr auto set_error (Bool auto&& b, char const* f = __builtin_FILE (), int line = __builtin_LINE ()) noexcept -> Void auto
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

		friend std::ostream& operator<< (std::ostream& os, _error const& e)
		{
			os << yellow << "error " << white << "(" << blue << e.__error << white << ") ";

			if (e._file != nullptr) 
			{
				os << red << (char const*) e._file << ":" << e._line << white;
			}

			

			return os;
		}

		private:
		bool __error;
		char* _file;
		int _line;
	};

	constexpr auto error (_error const& e) noexcept -> Error auto
	{
		return e;
	}




}

static_assert (Error <_error>);
}