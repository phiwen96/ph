export module Ph.Process.Signal;

import Ph.Concepts;
import Ph.Process.Core;

import Darwin;
import std;


export
{
    template <typename S>
    concept Signal = Error <S> and requires (S s)
    {
		true;
        // {s.set_continue_after (false)} noexcept -> Void;
        //S {[](int)->void{}};
    };
    
    
    template <int signal_to_catch, 
			  bool continue_after = true, 
			  bool dont_block_other_signals = true>
    struct sig : error
    {
        sig (auto&& lambda) noexcept : _sa {.sa_handler = lambda}, error {}
        {
            init ();
        }

		sig (sig&& other) noexcept : _sa {(struct sigaction&&) other._sa}, error {(error&&) other}
		{
			init ();
		}

		sig (sig const& other) noexcept : _sa {(struct sigaction const&) other._sa}, error {(error const&) other}
		{
			init ();
		}
        
    private:
		void init () noexcept 
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

			if (sigaction (signal_to_catch, &_sa, nullptr) == -1) 
			{
				error::set_error (true);
			}
		}

        struct ::sigaction _sa;
    };
    
    
}

static_assert (Signal <sig </*signal_to_catch = */SIGINT, /*continue = */true, /*dont_block_other_signals = */true>>);
