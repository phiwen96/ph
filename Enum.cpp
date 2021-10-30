export module Ph.Concepts.Enum;

import std;

namespace ph 
{

export template <typename T>
concept Enum = std::is_enum_v <T>;


enum E {};
enum class F {};
struct G {};

static_assert (Enum <E>);
static_assert (Enum <F>);
static_assert (not Enum <G>);
static_assert (not Enum <int>);
}