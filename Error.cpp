export module Ph.Concepts.Error;

import Ph.Concepts.Convertible_to;
import Ph.Concepts.Same_as;
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

	template <typename... T>
	struct error_t;

	template <typename T>
	struct error_t <T>
	{
		constexpr error_t (T& ref) noexcept : _ref {ref}
		{
			
		}

		constexpr error_t (error_t&& o) noexcept : _ref {o._ref}
		{
			
		}

		constexpr auto get_error () const noexcept -> Bool auto
		{
			return __error;
		}

		constexpr error_t& operator= (Bool auto&& e) noexcept
		{
			__error = e;

			return *this;
		}

		constexpr auto operator and (Bool auto&& b) noexcept -> error_t&
		{
			__error = __error and b;
			return *this;
		}

		constexpr auto operator or (Bool auto&& b) noexcept -> error_t&
		{
			__error = __error or b;
			return *this;
		}

		constexpr auto value () noexcept -> T& 
		{
			return _ref;
		}

		constexpr auto value () const noexcept -> T const& 
		{
			return _ref;
		}

		// constexpr operator T&& () noexcept 
		// {
		// 	return (T&&) _ref;
		// }

		// constexpr operator T& () noexcept 
		// {
		// 	return _ref;
		// }

		// constexpr operator T const& () noexcept 
		// {
		// 	return _ref;
		// }


		constexpr operator Bool auto () const noexcept 
		// requires (not Same_as <T, bool>)
		{
			return __error;
		}

	private:
		T& _ref;
		bool __error;
	};

	template <>
	struct error_t <>
	{
		constexpr error_t (Bool auto&& b) noexcept : __error {b}, _file {nullptr}, _line {0}
		{
			// std::cout << __error << std::endl;
		}

		constexpr error_t () noexcept : __error {false}, _file {nullptr}, _line {0}
		{
			// std::cout << __error << std::endl;
		}

		constexpr error_t (error_t&& other) noexcept : __error {(bool&&) other.__error}, _file (other._file), _line (other._line)
		{
			// std::cout << __error << std::endl;
		}

		constexpr error_t (error_t const& other) noexcept : __error {(bool const&) other.__error}, _file (other._file), _line (other._line)
		{
			// std::cout << __error << std::endl;
		}

		constexpr auto get_error () const noexcept -> Bool auto
		{
			return __error;
		}

		constexpr error_t& operator= (Bool auto&& e) noexcept
		{
			__error = e;

			return *this;
		}

		constexpr auto operator and (Bool auto&& b) noexcept -> error_t&
		{
			__error = __error and b;
			return *this;
		}

		constexpr auto operator or (Bool auto&& b) noexcept -> error_t&
		{
			__error = __error or b;
			return *this;
		}

		constexpr error_t& operator= (error_t const& rhs) noexcept
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

		constexpr operator Bool auto () const noexcept 
		{
			// std::cout << __error << std::endl;

			return __error;
		}

		// constexpr friend error_t& operator << (error_t& e, String auto const& s)
		// {
		// 	ph::string::append (e._file, s);
		// 	return e;
		// }

		// friend std::ostream& operator<< (std::ostream& os, error_t const& e)
		// {
		// 	os << yellow << "error " << white << "(" << blue << e.__error << white << ") ";

		// 	if (e._file != nullptr) 
		// 	{
		// 		os << red << (char const*) e._file << ":" << e._line << white;
		// 	}

			

		// 	return os;
		// }

		friend constexpr auto error (error_t const&, char const*, int) noexcept -> Error auto;

		private:
		bool __error;
		char* _file;
		int _line;
	};

	// template <typename... T>
	// constexpr auto error (error_t <T...> const& e, char const* _file = __builtin_FILE (), int _line = __builtin_LINE ()) noexcept -> Error auto
	// {
	// 	ph::string::append (e._file, _file, ph::string::to_string (_line));
	// 	return e;
	// }

	template <typename... T>
	constexpr auto exit_if_error (error_t <T...> const& e) noexcept -> void 
	{
		if (e)
		{
			std::cout << e << std::endl;
			exit (-1);
		}
	}



}

static_assert (Error <error_t <>>);
}