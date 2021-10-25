export module Concepts.Core;

import <type_traits>;


export 
{
	template <typename T>
	concept Const = std::is_const_v <T>;

	template <typename T>
	concept Ref = std::is_reference_v <T>;
}
