export module Ph.Message_queue;

export 
{
	template <typename M>
	concept Message_queue = requires (M m)
	{
		true;
	};

	struct message_queue 
	{

	};
}

static_assert (Message_queue <message_queue>);