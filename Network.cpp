module;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

export module Ph.Network;



import Ph.Concepts;
import Ph.Core;

export import Ph.Network.Port;
export import Ph.Network.IPv4;
export import Ph.Network.IPv6;

auto get_in_addr (sockaddr* sa) -> void*
{
	if (sa->sa_family == AF_INET)
	{
		return &(((struct sockaddr_in*) sa) -> sin_addr);
	}

	else 
	{
 		return &(((struct sockaddr_in6*) sa) -> sin6_addr);
	}
}


export 
{
	auto server (Port auto port, auto backlog = 10)
	{
		static char client_ipaddress [INET6_ADDRSTRLEN];
		static int yes;

		auto error = 0;
		auto serv_sock = 0;
		auto client_sock = 0;

		addrinfo * servinfo, * p;

		auto client_addr = sockaddr_storage {};
		auto sin_size = socklen_t {};

		auto hints = addrinfo
		{
			.ai_family = AF_UNSPEC, 
			.ai_socktype = SOCK_STREAM, 
			.ai_flags = AI_PASSIVE
		};

		if  ((error = getaddrinfo (NULL, port, &hints, &servinfo)) != 0) 
		{
			 fprintf (stderr, "getaddrinfo: %s\n", gai_strerror (error)); return 1;
		}

		for (p = servinfo; p != nullptr; p = p -> ai_next)
		{
			if ((serv_sock = socket (p -> ai_family, p -> ai_socktype, p -> ai_protocol)))
			{
				perror ("server: socket");
				continue;
			}

			if (setsockopt (serv_sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof (int)) == -1)
			{
				perror ("setsockopt");
				exit (1);
			}

			if (bind (serv_sock, p -> ai_addr, p -> ai_addrlen))
			{
				close (serv_sock);
				perror ("server: bind");
				continue;
			}

			break;
		}

		freeaddrinfo (servinfo);

		if (p == nullptr)
		{
			fprintf (stderr, "server: failed to bind\n");
		}

		if (listen (client_sock, backlog) == -1)
		{
			perror ("listen");
			exit (1);
		}


		while (1)
		{
			sin_size = sizeof (client_addr);

			client_sock = accept (serv_sock, (struct sockaddr*) &client_addr, &sin_size);

			if (client_sock == -1)
			{
				perror ("accept");
				continue;
			}

			inet_ntop (client_addr.ss_family, get_in_addr ((sockaddr*) &client_addr), client_ipaddress, sizeof (client_ipaddress));

			printf ("server: got connection from %s \n", client_ipaddress);

			if (send (client_sock, "Hello, world!", 13, 0) == -1)
			{
				perror ("send");
			}
			
			close (client_sock);

		}


	}
}



consteval auto Network_test ()
{
	return true;
}

static_assert (Network_test ());