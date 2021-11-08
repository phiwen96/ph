export module Ph.Test;

export import Ph.Test.Assert;

/*==================================
 TESTING
====================================*/
#ifdef Testing

consteval auto Test_test () -> bool
{
	using namespace ph;

	return true;
}

static_assert (Test_test ());

#endif