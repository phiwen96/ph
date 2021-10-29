export module Ph.Process.Message_queue;

import Ph.Concepts;

import Darwin;
import std;

export 
{
	template <typename M>
	concept Message_queue = requires (M m)
	{
		true;
	};

	// auto connect ()

	struct message_queue 
	{

	};
}

static_assert (Message_queue <message_queue>);