export module Ph.Process;

import Ph.Concepts.Core;
import Ph.Concepts.Return_value;
import Darwin;
import std;



export import Ph.Process.Signal;

export
{
    template <typename T>
    concept Process = Return_value <T> and requires (T const t)
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
                std::cout << "child ()" << std::endl;
                _id = getpid ();
                _parent_id = getppid ();
                return_value::set_done (true);
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
                        return_value::set_done (true);
                    }
                    
                    else
                    {
                        return_value::set_done (true);
                    }
                    
                } else
                {
                    return_value::set_done (true);
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
        
        // bool done () const noexcept
        // {
        //     return _done;
        // }
        
        // bool error () const noexcept
        // {
        //     return _error;
        // }
        
        // Value& value () noexcept
        // {
        //     return _value;
        // }
        
        // void set_done (bool done) noexcept
        // {
        //     std::cout << "setting done " << std::endl;
        //     _done = done;
        // }
        
        // void set_error (bool error) noexcept
        // {
        //     _error = error;
        // }
        
        // void set_value (Value&& value) noexcept
        // {
        //     _value = value;
        // }
        
        
    private:
        // Value _value;
        // bool _done, _error;
        pid_t _id;
        Child_id _child_id;
        Parent_id _parent_id;
    };
    
    template <bool spawn_and_wait = false>
    auto spawn () -> Process auto
    {
        return process <spawn_and_wait> {};
    }
    
    template <bool spawn_and_wait = false>
    auto spawn (auto&& lambda) -> Process auto
    requires requires ()
    {
        lambda ();
    }
    {
        Process auto r = process <spawn_and_wait> {};
        
        if (r.has_parent ())
        {
            lambda ();
        }
        
        //r.set_done ();
        
        return r;
    }
}


static_assert (Process <process <true>>);
