export module Ph.Dereferencable;

export template <typename T>
concept Dereferencable = requires (T t)
{
	{* t};
};




// module :private;

