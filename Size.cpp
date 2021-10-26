export module Ph.Concepts.Size;

import <type_traits>;

template <typename T>
concept Size = std::is_same_v <T, std::size_t>;
    