export module Ph.Concepts.Done;

import Ph.Concepts.Bool;
import Ph.Concepts.Void;

export
{
	template <typename D>
	concept Done = requires (D const d)
	{
		{d.get_done ()} noexcept -> Bool;

	} and requires (D d)
	{	
		{d.set_done (true)} noexcept -> Void;
	};

	struct done 
	{
		constexpr done () noexcept : _done {false}
		{

		}

		constexpr done (Bool auto&& b) noexcept : _done {b}
		{

		}

		constexpr done (done&& other) noexcept : _done {other._done}
		{

		}

		constexpr done (done const& other) noexcept : _done {other._done}
		{

		}

		auto get_done () const noexcept 
		{
			return _done;
		}

		auto set_done (Bool auto&& b) noexcept 
		{
			_done = b;
		}


	private:
		bool _done;
	};
}