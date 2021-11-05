[Ph]: https://github.com/phiwen96/ph
[C++]: https://www.cplusplus.com
[Make]: https://www.gnu.org/software/make/
[CMake]: https://cmake.org
[Markdown]: https://www.markdownguide.org/basic-syntax/
[dot]: https://graphviz.org/doc/info/lang.html
[UML]: https://en.wikipedia.org/wiki/Unified_Modeling_Language
[English]: https://en.wikipedia.org/wiki/English_language
[pandoc]: https://pandoc.org
[pandoc-plot]: https://github.com/LaurentRDC/pandoc-plot
[pandoc-plantuml-filter]: https://github.com/timofurrer/pandoc-plantuml-filter

Introduction
===============

<!-- An inline ![image](project_dependencies.ps){#id .class width=30 height=20px} -->

[Ph] aims to be the facto software for both [building](https://en.wikipedia.org/wiki/Software_build) and testing [C++] software.
It aims to cut loose from other languages in the [software development](https://en.wikipedia.org/wiki/Software_development), instead integrating them directly in the source code.



"Ph" is a lightning fast C++ library and also a build tool (such as [CMake] or [Make]) for turning C++ source code into something useful.




It introduces c++ concepts and modules, by which the former it is built around, thus, making it lucrative for industrial applications where the need for precision is critical, and where most of the bugs can be catched before the c++ files are even compiled, thus simply just generating syntax errors for developers. 
Introducing this core language feature has huge pros for industrial-strength generic components, AKA good software.
This is what we want! We dont want python's "throw in whatever type u desire", and not java's somewhat pragmatic "please specify the type". 
We want to be able to say "hey, other coders out there using this function im about to type, just throw in a String". 
String is just a concept that we specify. It could be everything from "std::string" to old plain c string "char const *". We say "hey, String can be either a "std::string" or a "char const*". OR it could be anything that we could do the following with:

```{#kuk .cpp .numberLines}
template <typename S>
concept String = requires (S s)
{
	s.size ();
	{s [0]} -> char;
}
```










 Goals with this project
 ===============

- [X] Motivation

- [ ] Just c++, even for building.

	All software are built around a set of programming languages, often one for front-end and one for back-end. The reason for this, unknown. One can only guess.

	I can not stress this enough, but writing software in one language has huge upside effects, and it's much cheaper. Your teams can speek the same language, thus making it much easier for further intrigues.  

- [ ] C++ interpreter
  
	Similar to python interpreter.








Details
===============





<!-- Project dependencies
---------------

The following graph describes that basically "ph" is a set of files which will either be transformed into a documentation file or into the executable software.  -->





---------------


### Source code written in

* [C++]

#### and built with 

* [Make]


About
===============




Documentation
===============
For building the documentation, we use the following languages:

* [Markdown]
* [dot]
* [UML]
* [English]

#### and the following tools
---------------

* [pandoc]
* [pandoc-plot]
* [pandoc-plantuml-filter]


Contribute
===============
At the moment, the project is very dependent on Make (for compiling C++ files into different things and then finally everything into an executable).

Also pandoc (for documentations). 
	
Reasons for this? 
It's still very young.

Please help me develop this project! At the moment there are just one developer.


Licensing
===============

[MIT](LICENSE) © 2021 Ph

<!-- Can be either open or proprietary. -->





# Ph.Language
## _"A simple, yet a powerful programming language aimed against code repetition"_



Ph.Language is a new programming language developed by Philip Wenkel. It is a simple, yet efficient, programming language written in the high performance language C++. It makes a great antidote for text repetition, whether it is for coding or really anything else. It also makes it much easier to create template files or folder structures for your projects, which drastically improves your production time and prevents you from making simple errors. I bet that, if you are like most people, creating a new project can really take time and effort. Probably you have some prepared base project structure which you pretty much copy-paste to the new one and just rename everything to fit your current project name. Enough of words, lets look at an example of how to use Ph.Language to simplify code repetition in c++. Then, we will look at how to use Ph.Language as a tool when writing a simple document. Last but not least, we will see how it can also be used with files and folders.

```c++
export module Ph.Concepts;

export import Ph.Concepts.Tuple;
export import Ph.Concepts.Bool;
export import Ph.Concepts.Done;
export import Ph.Concepts.Size;
export import Ph.Concepts.Bit;
export import Ph.Concepts.Byte;
export import Ph.Concepts.Core;
export import Ph.Concepts.Char;
export import Ph.Concepts.String;
export import Ph.Concepts.Strings;
export import Ph.Concepts.Pointer;
export import Ph.Concepts.Number;
export import Ph.Concepts.Error;
export import Ph.Concepts.Void;

export import Ph.Concepts.Iterator;
export import Ph.Concepts.Array;

export import Ph.Concepts.Class;
export import Ph.Concepts.Enum;
export import Ph.Concepts.Function;
export import Ph.Concepts.Any_of;
export import Ph.Concepts.File;
export import Ph.Concepts.Vector;
export import Ph.Concepts.Common;
export import Ph.Concepts.Constant;
export import Ph.Concepts.Range;
export import Ph.Concepts.Element;a
export import Ph.Concepts.Types;
```

```c++
export module Ph.Concepts;

@ (library) =
	Tuple
	Bool
	Types

$ (library : add library)
{
	export import Ph.Concepts.${library}
}

```

or 

```c++
export module Ph.Concepts;
@ (add library) -> {export import Ph.Concepts.${0}}
@ (library) =
	Tuple
	Bool
	Types
```

```c++
template <int>
struct Foo;

template <>
struct Foo <0>
{
    inline static constexpr int i = 0;  
};

template <>
struct Foo <1>
{
    inline static constexpr int i = 1;  
};

template <>
struct Foo <2>
{
    inline static constexpr int i = 2;  
};
```

As you can see, every template specialization of Foo is pretty much the same, except for two places, where only a number changes. Lets use Ph.Language to help us out with this boring and cumbersome code repetition.

```c++
template <int>
struct Foo;

@(type){inline static constexpr int}

$(0 i 3)
{
    template <>
    struct Foo <${i}>
    {
        ${type} i = ${i};  
    };
}
```

That's it!

Lets write a cv for our new job application!

```c++
@(first name){Philip}
@(last name){Wenkel}
@(name){${first name} ${last name}}
@(company name){Google}

My name is ${name} and I am interested in $(job){coding} at your company ${company name}.
On my spare time, i love ${job}! #{elaborate on this one...}

Yours sincerely, ${name}
```

This will result in the following output:

```c++
My name is Philip Wenkel and I am interested in coding at your company Google.
On my spare time, i love coding!

Yours sincerely, Philip Wenkel
```




<!-- ## Installation

Ph.Language requires [CMake](https://cmake.org) 3.19.4 to run. -->




## Usage
```sh
Ph.Language input_file.txt output_file.txt
```


TODO
===============
- [ ] [implement type function params <Ret(Args...)> -> Typelist](Function.cpp)
- [ ] [implement type function ret <Ret(Args...)> -> Typelist](Function.cpp)




<!-- ![diagram](Lib.ps) -->