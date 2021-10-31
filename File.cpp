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


		struct file : error
		{
			
			file (String auto&& path, String auto&& mode) : _file {file::open (path, mode)}, _data {}
			{
				if (_file == nullptr)
				{
					std::cout << "error";
					error::set_error (true);
				}
			}

			file (String auto&& path) : _file {file::open (path, "a")}, _data {}
			{
				if (_file == nullptr)
				{
					std::cout << "error";
					error::set_error (true);
				}
			}

			file (FILE*&& file) : _file {(FILE*&&) file}, _data {}
			{

			}

			file (file&& other) : _file {(FILE*&&) other._file}, _data {(std::string&&) other._data}
			{

			}

			file (file const& other) : _file {other._file}, _data {other._data}
			{
				
			}

			~file ()
			{

				fclose (_file);
			}

			// cout << file {} << endl;
			friend std::ostream & operator << (std::ostream& os, file const& f)
			{

				return os;
			}

			// file {} << "hello"
			friend auto& operator << (file& f, String auto const& s)
			{
				f._data += ph::c_string (s);
				return f;
			}

			constexpr auto data () noexcept -> Pointer auto
			{
				return _data.data ();
			}

		private:
			auto open (String auto&& path, String auto&& permissions) noexcept -> Pointer auto
			{
				return fopen (c_string (path), c_string (permissions));
			}

			FILE* _file;
			std::string _data;
		};

		[[nodiscard]] auto open (String auto&& path) -> File auto 
		{
			return ph::file {path};
		}

		[[nodiscard]] auto open (String auto&& path, String auto&& permissions) -> File auto 
		{
			return ph::file {path, permissions};
		}

		


	}
}




static_assert (ph::File <ph::file>);

