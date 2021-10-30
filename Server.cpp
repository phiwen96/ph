export module Ph.Network.Server;


import Ph.Concepts;
import Darwin;

export 
{
	
	inline auto server (Integer auto port)
	{
		auto get_in_addr = [] (sockaddr* sa) -> void*
		{
			if (sa->sa_family == AF_INET)
			{
				return &(((struct sockaddr_in*) sa) -> sin_addr);
			}

			else 
			{
				return &(((struct sockaddr_in6*) sa) -> sin6_addr);
			}
		};

		auto backlog = 10;

		static char client_ipaddress [INET6_ADDRSTRLEN];
		static int yes;

		auto error = 0;
		auto serv_sock = 0;
		auto client_sock = 0;

		addrinfo * servinfo, * p;

		struct sockaddr_storage client_addr {};
		auto sin_size = socklen_t {};

		auto hints = addrinfo
		{
			.ai_family = AF_UNSPEC, 
			.ai_socktype = SOCK_STREAM, 
			.ai_flags = AI_PASSIVE
		};

		

		if  ((error = getaddrinfo (nullptr, to_string (port), &hints, &servinfo)) != 0) 
		{
			printf ("error on line %i\n", __LINE__);
			fprintf (stderr, "getaddrinfo: %s\n", gai_strerror (error)); return 1;
		}

		for (p = servinfo; p != nullptr; p = p -> ai_next)
		{
			if ((serv_sock = socket (p -> ai_family, p -> ai_socktype, p -> ai_protocol)) == -1)
			{
				printf ("error on line %i\n", __LINE__);
				perror ("server: socket");
				
				continue;
			}

			if (setsockopt (serv_sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof (int)) == -1)
			{
				printf ("error on line %i\n", __LINE__);
				perror ("setsockopt");
				exit (1);
			}

			if (bind (serv_sock, p -> ai_addr, p -> ai_addrlen) == -1)
			{
				printf ("error on line %i\n", __LINE__);
				close (serv_sock);
				perror ("server: bind");
				continue;
			}

			break;
		}

		freeaddrinfo (servinfo);

		if (p == nullptr)
		{
			printf ("error on line %i\n", __LINE__);
			fprintf (stderr, "server: failed to bind\n");
		}

		if (listen (serv_sock, backlog) == -1)
		{
			printf ("error on line %i\n", __LINE__);
			perror ("listen");
			exit (1);
		}


		while (1)
		{
			sin_size = sizeof (client_addr);

			client_sock = accept (serv_sock, (struct sockaddr*) &client_addr, &sin_size);

			if (client_sock == -1)
			{
				printf ("error on line %i\n", __LINE__);
				perror ("accept");
				continue;
			}

			inet_ntop (client_addr.ss_family, get_in_addr ((sockaddr*) &client_addr), client_ipaddress, sizeof (client_ipaddress));

			printf ("server: got connection from %s \n", client_ipaddress);

			if (send (client_sock, "Hello, world!", 13, 0) == -1)
			{
				printf ("error on line %i\n", __LINE__);
				perror ("send");
			}

			close (client_sock);

		}


	}
}