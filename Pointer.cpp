export module Ph.Concepts.Pointer;


template <typename T>
struct pointer;

template <typename T>
struct pointer <T*> 
{
	static constexpr bool value = true;
};



export 
{
	template <typename T>
	concept Pointer = pointer <T>::value;
}
