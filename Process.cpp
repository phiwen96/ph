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
        using Child_id = std::optional <pid_t>;
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
                return_value::set_error ();
            }
            
            else if (value == 0) // child
            {
                _id = getpid ();
                _parent_id = getppid ();
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
                        return_value::set_error ();
                    }
                }
            }
        }
        
        process (process&& other) noexcept : _child_id {(Child_id&&) other._child_id}, _parent_id {(Parent_id&&) other._parent_id}
        {
            
        }
        
        process (process const& other) noexcept : _child_id {(Child_id const&) other._child_id}, _parent_id {(Parent_id const&) other._parent_id}
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
        
        r.set_done ();
        
        return r;
    }
}
