export module Ph.Convertible_to;

import <type_traits>;

export template <typename T, typename U>
concept Convertible_to = std::is_convertible_v <T, U> and (sizeof (U) >= sizeof (T));


// module :private;

// not valid if there could be a loss of data
static_assert (not Convertible_to <long, int>);

static_assert (Convertible_to <short, int>);
static_assert (Convertible_to <short, short>);
