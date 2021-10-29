export module Ph.Concepts.Error;

import Ph.Concepts.Bool;
import Ph.Concepts.Void;

export 
{
	template <typename E>
	concept Error = requires (E const e)
	{
		{e.error ()} noexcept -> Bool;

	} and requires (E e)
	{
		{e.set_error (true)} noexcept -> Void;
	};
}