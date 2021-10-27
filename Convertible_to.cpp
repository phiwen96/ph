export module Ph.Convertible_to;


export template <typename T, typename U>
concept Convertible_to = (sizeof (U) >= sizeof (T)) and requires (T t, U u)
{
	u = t;
};


// module :private;

// not valid if there could be a loss of data
static_assert (not Convertible_to <long, int>);

static_assert (Convertible_to <short, int>);
static_assert (Convertible_to <short, short>);
