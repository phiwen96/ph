export module concepts.Number.Unsigned;

import <type_traits>;

export template <typename T>
concept Unsigned = std::is_same_v <T, unsigned short>
    or std::is_same_v <T, unsigned short int>
    or std::is_same_v <T, unsigned>
    or std::is_same_v <T, unsigned int>
    or std::is_same_v <T, unsigned long>
    or std::is_same_v <T, unsigned long int>
    or std::is_same_v <T, unsigned long long>
    or std::is_same_v <T, unsigned long long int>;