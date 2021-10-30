export module Ph.Dereferencable;

namespace ph 
{

export template <typename T>
concept Dereferencable = requires (T t)
{
	{* t};
};

}


// module :private;

