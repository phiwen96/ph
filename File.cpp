export module Ph.Concepts.File;

/*
TODO

create new foo.cpp or foo2.cpp if already exists if calling open () without args
*/

#include <fstream>

import Ph.Concepts.Same_as;
import Ph.Concepts.String;
import Ph.Concepts.Error;
import Ph.Concepts.Pointer;
import Ph.Concepts.Array;
import Ph.Concepts.Bool;
import Darwin;

import std;

namespace ph 
{

	export 
	{

		

		template <typename F>
		concept File = Error <F> and requires (F f)
		{
			F {"/usr/bin/hello", "a"};
			F {"/usr/bin/hello"};
			std::cout << f;
			f << "hello";
		};

		[[nodiscard]] auto curr_dir () noexcept -> String auto 
		{
			return std::string {std::filesystem::current_path ().c_str ()};
		}

		[[nodiscard]] auto exists (String auto&& path) noexcept -> Bool auto
		{
			return std::filesystem::exists (c_string (path));
		}

		auto exists (File auto const& file) noexcept -> Bool auto
		requires requires ()
		{
			{file.exists ()} -> Bool;
		}
		{	
			return file.exists ();
		}


		struct file : _error
		{
		private:
			FILE* _file;
			std::string _data;
			std::string _path;

			constexpr static auto open (String auto&& path, String auto&& permissions) noexcept -> Pointer auto
			{
				return fopen (c_string (path), c_string (permissions));
			}

			constexpr auto rename (String auto&& new_name) noexcept -> Error auto 
			{
				if (rename (_path, ph::c_string (new_name)))
				{
					return true;

				} else 
				{
					_path = c_string (new_name);
					return false;
				}
			}

			constexpr auto read () noexcept -> void
			{
				fseek (_file , 0L , SEEK_END);
				auto lSize = ftell (_file);
				rewind (_file);

				/* allocate memory for entire content */
				Pointer auto buffer = calloc( 1, lSize+1 );
				if (!buffer) _error::set_error (true);

				/* copy the file into the buffer */	
				if (fread (buffer , lSize, 1 , _file) != 1) _error::set_error (true);
			}

			public:

			constexpr auto end_of_file () const noexcept -> Bool auto 
			{
				if (feof (_file))
				{
					return true;

				} else 
				{
					return false;
				}
			}

			auto size () const noexcept -> auto 
			{
				auto prev = ftell (_file);
				fseek (_file, 0L, SEEK_END);
				auto sz = ftell (_file);
				fseek (_file, prev, SEEK_SET);
				return sz;
			}
			
			file (String auto&& path, String auto&& permissions) : _error {}, _file {file::open (ph::c_string (path), ph::c_string (permissions))}, _data {}
			{
				if (_file == nullptr)
				{
					std::cout << "error " << __LINE__ << std::endl;
					_error::set_error (true);
				} else 
				{
					file::read ();
				}
			}

			file (String auto&& path) : _error {}, _file {file::open (ph::c_string (path), "rw")}, _data {}
			{
				if (_file == nullptr)
				{
					std::cout << "error " << __LINE__ << std::endl;
					_error::set_error (true);
				} else 
				{
					file::read ();
				}
			}

			// file (FILE*&& file) : _file {(FILE*&&) file}, _data {}
			// {

			// }

			file (file&& other) : _error {(_error&&) other}, _file {(FILE*&&) other._file}, _data {(std::string&&) other._data}
			{

			}

			file (file const& other) : _error {(_error const&) other}, _file {other._file}, _data {other._data}
			{
				
			}

			~file ()
			{

				fclose (_file);
			}

			// cout << file {} << endl;
			friend std::ostream & operator << (std::ostream& os, file const& f)
			{
				os << f._data;
				return os;
			}

			// file {} << "hello"
			friend auto& operator << (file& f, String auto const& s)
			{
				fwrite (ph::c_string (s), sizeof (char), ph::string::len (s), f._file);
				f._data += ph::c_string (s);
				return f;
			}

			constexpr auto data () noexcept -> Pointer auto
			{
				return _data.data ();
			}
		};

		[[nodiscard]] constexpr auto open (String auto&& path) noexcept -> File auto 
		{
			return ph::file {path};
		}

		[[nodiscard]] constexpr auto open (String auto&& path, String auto&& permissions) noexcept -> File auto 
		{
			return ph::file {path, permissions};
		}



		


	}
}




static_assert (ph::File <ph::file>);

