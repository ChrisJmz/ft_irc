#include "signal.hpp"
#include <iostream>

bool sig::stopServer = false;

void sig::signalHandler(int signum)
{
	if (signum == SIGINT)
	{
		sig::stopServer = true;
	}
}
