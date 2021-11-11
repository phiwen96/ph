export module Ph;

export import Ph.Test;
export import Ph.Test.Assert;
export import Ph.Bool;
export import Ph.Const;
export import Ph.Convertible_to;
export import Ph.Number.Float;
export import Ph.Number.Integer;
export import Ph.Iterator;
export import Ph.Number;
export import Ph.Pointer;
export import Ph.Range;
export import Ph.Reference;
export import Ph.Number.Signed;
export import Ph.Size;
export import Ph.Number.Unsigned;
export import Ph.Nothing;
export import Ph.Something;
export import Ph.Decrementable;
export import Ph.Incrementable;
export import Ph.Referenceable;
export import Ph.Dereferenceable;
export import Ph.Mimic;
export import Ph.AI;





/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;

consteval auto Ph_test () -> bool
{
	using namespace ph;
	
	return true;
}

static_assert (Ph_test ());

#endif