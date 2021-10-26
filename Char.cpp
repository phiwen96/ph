export module Ph.Concepts.Char;

import <type_traits>;

template <typename T>
concept Char = 
    std::is_same_v <T, char>
    or std::is_same_v <T, signed char>
    or std::is_same_v <T, unsigned char>
    or std::is_same_v <T, char16_t>
    or std::is_same_v <T, char32_t>
    or std::is_same_v <T, wchar_t>;
