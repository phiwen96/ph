export module Ph.Same_as;

import <type_traits>;

export template <typename T, typename U>
concept Same_as = std::is_same_v <T, U>;




// module :private;

static_assert (Same_as <int, int>);
static_assert (not Same_as <char, int>);
