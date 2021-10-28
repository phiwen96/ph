export module Ph.Fork;

import std;
import Darwin;

auto _spawn ()
{
	auto child_id = fork ();

	if (child_id == -1) [[unlikely]] // error
		{
			// throw;
			return -1;
		} 

		else if (child_id == 0) // child
		{
			return lambda ();
		}

		else // parent
		{
			return child_id;
		}
}

export 
{
	auto spawn (auto&& lambda)
	{
		signal (SIGCHLD, SIG_IGN); // don't wait !

		_spawn (lambda);
	}
}