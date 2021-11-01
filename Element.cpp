export module Ph.Concepts.Element; 

import Ph.Concepts.Size;


namespace ph 
{
	export 
	{
		template <typename T>
		struct element_t 
		{

		};


		template <typename T>
		requires requires ()
		{
			typename T::value_type;
		}
		struct element_t <T>
		{
			using element = typename T::value_type;
		};	


		template <typename T>
		requires requires ()
		{
			typename T::element;
		}
		struct element_t <T>
		{
			using element = typename T::element;
		};	

		template <typename T, Size auto S>
		struct element_t <T [S]>
		{
			using element = T;
		};

		template <typename T>
		struct element_t <T []>
		{
			using element = T;
		};

		template <typename T>
		struct element_t <T*>
		{
			using element = T;
			
		};

		template <typename E>
		concept Element = requires (E e)
		{
			true;
		};

		template <Element E>
		using element = typename element_t <E>::element;
	}
}