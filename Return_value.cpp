export module Ph.Concepts.Return_value;

import Ph.Concepts.Core;
import std;

export template <typename T>
concept Return_value = requires (T t)
{
#define Value std::remove_cvref_t <decltype (t.value ())>
    
    {T {}} noexcept;
    {T {Value {}}} noexcept;
    {T {(T&&) t}} noexcept;
    {T {(T const&) t}} noexcept;
    
    {t.done ()} noexcept -> Bool;
    {t.error ()} noexcept -> Bool;
    {t.value ()} noexcept -> Ref;
    
    
    
    {t.set_value (Value {})} noexcept -> Void;
#undef Value
};







export template <typename _Value>
struct return_value
{
    using Value = _Value;
    
    return_value (Value value) noexcept : _value {value}
    {
        
    }
    
    return_value () noexcept = default;
    
    return_value (return_value && other) noexcept : _value {(Value&&) other._value}, _done {other._done}, _error {other._error}
    {
        
    }
    
    return_value (return_value const& other) noexcept : _value {other.value}, _done {other._done}, _error {other._error}
    {
        
    }
    
    bool done () const noexcept
    {
        return _done;
    }
    
    bool error () const noexcept
    {
        return _error;
    }
    
    Value& value () noexcept
    {
        return _value;
    }
    
    void set_done () noexcept
    {
        _done = true;
    }
    
    void set_error () noexcept
    {
        _error = true;
    }
    
    void set_value (auto&& value) noexcept
    {
        _value = value;
    }
    
    
private:
    Value _value;
    bool _done {false};
    bool _error {false};
};

static_assert (Return_value <return_value <int>>);

