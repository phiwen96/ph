export module Ph.Concepts.File;

import Ph.Concepts.String;
import Ph.Concepts.Error;
import Ph.Concepts.Pointer;
import Ph.Concepts.Array;


import std;

namespace ph 
{
export 
{

	auto open (String auto&& path, String auto&& mode) -> Error auto 
	{
		
		// if (_file == NULL)
		// {
		// 	error::set_error (true);
		// }
	}

	template <typename F>
	concept File = Error <F> and requires (F f)
	{
		F {"/usr/bin/hello", "a"};
		std::cout << f;
		{ph::data (f)} -> Pointer;
		// f << "hello" << std::endl;
	};


	struct file : error
	{
		constexpr file (String auto&& path, String auto&& mode) : _file {fopen (c_string (path), c_string (mode))}
		{
			if (_file == NULL)
			{
				error::set_error (true);
			}
		}

		// cout << file {} << endl;
		friend std::ostream & operator << (std::ostream& os, file const& f)
		{

			return os;
		}

		

		friend std::istream & operator >> (std::istream & is, File auto& s)
		{
			is.get_line (ph::data (s._data), ph::len (s._data));
			return is;
		}

		constexpr auto data () noexcept -> Pointer auto
		{
			return _data.data ();
		}

	private:
		FILE * _file;
		std::string _data;
	};

}


}

static_assert (ph::File <ph::file>);