export module Ph.Process;

import Ph.Concepts;
import Darwin;
import std;


export import Ph.Process.Core;
export import Ph.Process.Signal;
export import Ph.Process.Message_queue;
export import Ph.Process.Semaphore;
export import Ph.Process.Shared_memory;
export import Ph.Process.Unix_socket;

namespace ph 
{

export
{
    

	
    
    
    auto send (Signal auto&& s, Process auto&& destination) -> Void auto
    {
        
    }
    
    
    
    
    template <auto spawn_and_wait = false>
    struct process : error, done
    {
        using Value = pid_t;
        using Child_id = std::optional <Value>;
        using Parent_id = Child_id;
	
        
        constexpr process () noexcept : error {}, done {}
        {
            if constexpr (not spawn_and_wait)
            {
                signal (SIGCHLD, SIG_IGN); // don't wait !
            }
            
            Value value;
            
            value = fork ();
            
            if (value == -1) [[unlikely]] // error
            {
                error::set_error (true);
            }
            
            else if (value == 0) // child
            {
                _id = getpid ();
                _parent_id = getppid ();
                //return_value::set_done (true);
            }
            
            else // parent
            {
                _id = getpid ();
                
                _child_id = value;
                
                if constexpr (spawn_and_wait)
                {
                    int rv;
                    wait (&rv);
                    
                    if (rv == -1)
                    {
                        //return_value::set_done (true);
                    }
                    
                    else
                    {
                        //return_value::set_done (true);
                    }
                    
                } else
                {
                    //return_value::set_done (true);
                }
            }
        }
        
        constexpr process (process&& other) noexcept : _child_id {(Child_id&&) other._child_id}, _parent_id {(Parent_id&&) other._parent_id}, error {(error&&) other}, done {(done&&) other}
        {
            
        }
        
        constexpr process (process const& other) noexcept : _child_id {(Child_id const&) other._child_id}, error {(error const&) other}, done {(done const&) other}
        {
            
        }
        
        constexpr bool has_child () const noexcept
        {
            return _child_id.has_value ();
        }
        
        constexpr bool has_parent () const noexcept
        {
            return _parent_id.has_value ();
        }

		constexpr auto raise (Signal auto&& s, Process auto&& destination)
		{

		}
        
    private:
		Value _id;
        Child_id _child_id;
        Parent_id _parent_id;
    };
    

	template <bool spawn_and_wait = false>
    constexpr auto spawn () -> Process auto
    {
        Process auto p = process <spawn_and_wait> {};
		p.set_done (true);
		return p;
    }

    constexpr auto spawn_and_wait () -> Process auto
    {
        return spawn <true> ();
    }
    
    template <bool spawn_and_wait = false>
    constexpr auto spawn_and_work (auto&& work) -> Process auto
    requires requires (process <false> & p)
    {
        work (p);
    }
    {
        Process auto p = process <spawn_and_wait> {};
        

        if (p.has_parent ())
        {
            work (p); // lambda has to set the process to done manually

        } else 
		{
			p.set_done (true); // parent process should automatically be set to done;
		}
        
        return p;
    }
    
}


static_assert (Process <process <true>>);


}