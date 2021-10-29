export module Ph.Process;

import Ph.Concepts;
import Darwin;
import std;



export import Ph.Process.Signal;

export
{
    template <typename T>
    concept Process = Error <T> and requires (T const t)
    {
        {t.has_child ()} noexcept -> Bool;
        {t.has_parent ()} noexcept -> Bool;
    };

	
    
    
    auto send (Signal auto&& s, Process auto&& destination) -> Void auto
    {
        
    }
    
    
    
    
    template <auto spawn_and_wait = false>
    struct process : return_value <pid_t>
    {
        using Value = pid_t;
        using Child_id = std::optional <Value>;
        using Parent_id = Child_id;
		using return_value::return_value;
        
        process () noexcept
        {
            if constexpr (not spawn_and_wait)
            {
                signal (SIGCHLD, SIG_IGN); // don't wait !
            }
            
            auto& value = return_value::value ();
            
            value = fork ();
            
            if (value == -1) [[unlikely]] // error
            {
                return_value::set_error (true);
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
        
        process (process&& other) noexcept : _child_id {(Child_id&&) other._child_id}, _parent_id {(Parent_id&&) other._parent_id}, return_value {(return_value&&) other}
        {
            
        }
        
        process (process const& other) noexcept : _child_id {(Child_id const&) other._child_id}, _parent_id {(Parent_id const&) other._parent_id}, return_value {(return_value const&) other}
        {
            
        }
        
        bool has_child () const noexcept
        {
            return _child_id.has_value ();
        }
        
        bool has_parent () const noexcept
        {
            return _parent_id.has_value ();
        }
        
    private:
        pid_t _id;
        Child_id _child_id;
        Parent_id _parent_id;
    };
    

	template <bool spawn_and_wait = false>
    auto spawn () -> Process auto
    {
        Process auto p = process <spawn_and_wait> {};
		p.set_done (true);
		return p;
    }
    
    template <bool spawn_and_wait = false>
    auto spawn (auto&& lambda) -> Process auto
    requires requires (process <false> & p)
    {
        lambda (p);
    }
    {
        Process auto p = process <spawn_and_wait> {};
        

        if (p.has_parent ())
        {
            lambda (p); // lambda has to set the process to done manually

        } else 
		{
			p.set_done (true); // parent process should automatically be set to done;
		}
        
        return p;
    }
    
}


static_assert (Process <process <true>>);
