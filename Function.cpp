export module Concepts.Function;

export import <type_traits>;

export template <typename T>
concept Function = std::is_function_v <std::decay_t <T>>;
        