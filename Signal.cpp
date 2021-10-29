


export module Ph.Process.Signal;

import Ph.Concepts;

import Darwin;
import std;


export
{
    template <typename S>
    concept Signal = requires (S s)
    {
		true;
        // {s.set_continue_after (false)} noexcept -> Void;
        //S {[](int)->void{}};
    };
    
    
    template <bool continue_after = true, bool dont_block_other_signals = true>
    struct sig : return_value <bool>
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
            
			if constexpr (dont_block_other_signals)
			{
				sigemptyset (&_sa.sa_mask);
			}

			if (sigaction(SIGUSR1, &_sa, NULL) == -1) 
			{
				return_value::set_error (true);
			}
     
        }
        
    private:
        using SS = __sigaction;
        SS _sa;
    };
    
    
}

static_assert (Signal <sig </*continue = */true>>);
