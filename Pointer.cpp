export module Ph.Concepts.Pointer;

import <type_traits>;

template <typename T>
concept Pointer = std::is_pointer_v <T>;