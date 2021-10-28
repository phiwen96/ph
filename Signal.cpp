


export module Ph.Process.Signal;

import Ph.Concepts;

import Darwin;
import std;


export
{
    template <typename S>
    concept Signal = requires (S s)
    {
        {s.set_continue_after (false)} noexcept -> Void;
        //S {[](int)->void{}};
    };
    
    
    template <bool continue_after = true>
    struct sig
    {
        sig (auto&& lambda) noexcept : _sa {.sa_handler = lambda}
        {
            if constexpr (continue_after)
            {
                _sa.sa_flags = SA_RESTART;
                
            } else
            {
                _sa.sa_flags = 0;
            }
            
            sigemptyset (&_sa.sa_mask);
        }
        
        auto set_continue_after (Bool auto cont) noexcept
        {
            if (cont)
            {
                _sa.sa_flags = SA_RESTART;
            }
            
            else
            {
                _sa.sa_flags = 0;
            }
        }
        
        
        
    private:
        using SS = __sigaction;
        SS _sa;
    };
    
    
}

static_assert (Signal <sig </*continue = */true>>);
