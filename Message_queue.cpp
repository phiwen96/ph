export module Ph.Process.Message_queue;

import Ph.Concepts;
import Ph.Process.Core;
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
		
		message_queue (String auto&& id) noexcept 
		{
			auto key = ftok (c_string (id), 'b');
			_ms_id = msgget (key, 0666 | IPC_CREAT);

			
		}

		auto send (auto&& msg) 
		{
			auto e = msgsnd (_ms_id, &msg, sizeof (msg), 0);
		}

		auto receive (auto&& msg)
		{
			msgrcv (_ms_id, &msg, sizeof (msg), 2, 0);
		}
		
		private:
		int _ms_id;
	};

	auto connect (Message_queue auto&& m, Process auto&& p) 
	{

	}
}

static_assert (Message_queue <message_queue>);