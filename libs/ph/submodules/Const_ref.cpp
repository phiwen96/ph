export module Ph.Const_ref;
import Ph.Const;
import Ph.Reference;

export namespace ph 
{
	template <typename T>
	concept Const_ref = Const <T> and Reference <T>;
}



/*==================================
 TESTING
====================================*/
#ifdef Testing

import Ph.Test;

#endif

