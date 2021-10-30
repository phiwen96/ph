export module Ph.Concepts.Not;

import Ph.Concepts.Same_as;

namespace ph 
{

export template <typename T, typename U>
concept Not = not Same_as <T, U>;

static_assert (Not <int, char>);
static_assert (Not <int, int&>);
static_assert (not Not <int, int>);

}