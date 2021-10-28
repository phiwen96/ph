export module Ph.Concepts.Same_as;

// import <type_traits>;

template <typename T, typename U>
struct same 
{
	constexpr static bool value = false;
};

template <typename T>
struct same <T, T>
{
	constexpr static bool value = true;
};


export template <typename T, typename U>
concept Same_as = same <T, U>::value;//std::is_same_v <T, U>;




// module :private;

static_assert (Same_as <int, int>);
static_assert (not Same_as <char, int>);
