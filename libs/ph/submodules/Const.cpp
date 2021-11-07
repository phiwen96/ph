export module Ph.Const;

export namespace ph 
{
	template <typename T>
	concept Const = not requires (T t0, T t1)
	{
		t0 = t1;
	};
}



/*==================================
 TESTING
====================================*/
#ifdef Testing

#endif

