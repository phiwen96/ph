export module concepts.Numbers.Signed;

import <type_traits>;

template <typename T>
concept Signed = std::is_same_v <T, short>
    or std::is_same_v <T, short int>
    or std::is_same_v <T, signed short>
    or std::is_same_v <T, signed short int>
    or std::is_same_v <T, int>
    or std::is_same_v <T, signed>
    or std::is_same_v <T, signed int>
    or std::is_same_v <T, long>
    or std::is_same_v <T, long int>
    or std::is_same_v <T, signed long>
    or std::is_same_v <T, signed long int>
    or std::is_same_v <T, long long>
    or std::is_same_v <T, long long int>
    or std::is_same_v <T, signed long long>
    or std::is_same_v <T, signed long long int>;