export module Ph.Concepts.Class;

import Ph.Concepts.Core;

import std;


namespace ph 
{

template <typename T, typename = std::void_t <>>
struct is_class : std::false_type {};

template <typename T>
struct is_class <T, std::void_t <int T::*>> : std::true_type {};

export template <typename T>
concept Class = is_class <T>::value;


class C {};

static_assert (Class <C>);
static_assert (not Class <int>);

}