export module Ph.Concepts.Return_value;

import Ph.Concepts.Core;
import std;


export
{
    template <typename T>
    concept Return_value = requires (T t)
    {
#define Value std::remove_cvref_t <decltype (t.value ())>
        
        {T {}} noexcept;
        {T {(Value&&) Value {}}} noexcept;
        {T {(T&&) t}} noexcept;
        {T {(T const&) t}} noexcept;
        
        
        {t.set_value ((Value&&) Value {})} noexcept -> Void;
        {t.set_done (true)} noexcept -> Void;
        {t.set_error (true)} noexcept -> Void;
        {t.value ()} noexcept -> Ref;
        
    } and requires (T const t)
    {
        {t.done ()} noexcept -> Bool;
        {t.error ()} noexcept -> Bool;
#undef Value
    };
    
    
    
    
    
    
    
    template <typename _Value>
    struct return_value
    {
        using Value = _Value;
        
        return_value (Value&& value) noexcept : _value {(Value&&) value}, _done {false}, _error {false}
        {
            
        }
        
        return_value () noexcept : _value {}, _done {false}, _error {false}
        {
            
        }
        
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
        
        void set_done (bool done) noexcept
        {
            _done = done;
        }
        
        void set_error (bool error) noexcept
        {
            _error = error;
        }
        
        void set_value (auto&& value) noexcept
        {
            _value = value;
        }
        
        
    protected:
        Value _value;
        bool _done;
        bool _error;
    };
    
}


static_assert (Return_value <return_value <int>>);

