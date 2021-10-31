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
		concept File = Same_as <F, FILE*> or Error <F> and requires (F f)
		{
			F {"/usr/bin/hello", "a"};
			std::cout << f;
			f << "hello";
		};

		struct file : error
		{
			
			file (String auto&& path, String auto&& mode);

			file (String auto&& path);

			file (FILE*&& file);

			file (file&& other);

			file (file const& other);

			~file ();

			// cout << file {} << endl;
			friend std::ostream & operator << (std::ostream& os, file const& f);

			// file {} << "hello"
			friend auto& operator << (file& f, String auto const& s);

			constexpr auto data () noexcept -> Pointer auto;

		private:
			FILE * _file;
			std::string _data;
		};

		auto exists (String auto&& path) noexcept -> Bool auto;

		auto open (String auto&& path, String auto&& mode) -> File auto;

		auto open (String auto&& path) -> File auto;


		

	}
}

namespace ph 
{
			
			ph::file (ph::String auto&& path, ph::String auto&& mode) : _file {open (path, mode)}
			{
				if (_file == nullptr)
				{
					std::cout << "error";
					error::set_error (true);
				}
			}

			ph::file (ph::String auto&& path) : _file {open (path)}
			{
				if (_file == nullptr)
				{
					std::cout << "error";
					error::set_error (true);
				}
			}

			ph::file (FILE*&& file) : _file {(FILE*&&) file}
			{

			}

			ph::file (ph::file&& other) : _file {(FILE*&&) other._file}, _data {(std::string&&) other._data}
			{

			}

			ph::file (ph::file const& other) : _file {other._file}, _data {other._data}
			{
				
			}

			ph::~file ()
			{
				fclose (_file);
			}

			// cout << file {} << endl;
			std::ostream & operator << (std::ostream& os, ph::file const& f)
			{

				return os;
			}

			// file {} << "hello"
			auto& operator << (file& f, ph::String auto const& s)
			{
				return f;
			}

			constexpr auto ph::data () noexcept -> ph::Pointer auto
			{
				return _data.data ();
			}


auto ph::exists (ph::String auto&& path) noexcept -> ph::Bool auto
		{
			return std::filesystem::exists (c_string (path));
		}

		auto ph::open (ph::String auto&& path, ph::String auto&& mode) -> ph::File auto
		{
			FILE* f;

			if ((f = fopen (ph::c_string (path), ph::c_string (mode))) == nullptr)
			{
				std::cout << "error";
				f = nullptr;
			}
			return ph::file {(FILE*&&) f};
			// return file;
		}

		auto ph::open (ph::String auto&& path) -> ph::File auto
		{
			FILE* file;

			if ((file = fopen (ph::c_string (path), "rwa")) == nullptr)
			{
				std::cout << "error";
				file = nullptr;
			}

			return file;
		}
		


static_assert (File <file>);

}