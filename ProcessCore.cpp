export module Ph.Process.Core;

import Ph.Concepts;
import Darwin;
import std;

export 
{
	template <typename T>
    concept Process =  Error <T> and Done <T> and requires (T const t)
    {
        {t.has_child ()} noexcept -> Bool;
        {t.has_parent ()} noexcept -> Bool;
    };
}