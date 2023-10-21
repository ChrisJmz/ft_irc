/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_irc.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:19:48 by cjimenez          #+#    #+#             */
/*   Updated: 2023/10/09 13:54:38 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IRC
#define FT_IRC

#include <arpa/inet.h>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <exception>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <netinet/in.h>
#include <netdb.h>
#include <new>
#include <openssl/sha.h>
#include <poll.h>
#include <signal.h>
#include <sstream>
#include <stdexcept>
#include <string>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <utility>
#include <vector>
#include "Colors.h"
#include "log_event.hpp"
#include "signal.hpp"

# define SERVER_PREFIX ":ggwp.42.fr"
# define SERVER_NAME "IRC"
# define SERVER_CREATION "42/24/4224"
# define SERVER_VERSION "0.01"

# define ADMIN_INFO_1 "IRC EN GRP"
# define ADMIN_INFO_2 "IRC FINI"
# define ADMIN_EMAIL "cjimenez@student.42.fr wiharel@student.42.fr pli@student.42.fr"

bool is_in( char c, std::string str );

template <typename T>
bool is_in_list( std::list<T> list, T elem )
{
	typename std::list<T>::iterator it = list.begin();
	for ( ; it != list.end(); it++ )
	{
		if ( *it == elem )
		{
			return ( true );
		}
	}
	return ( false );
}

bool is_channel( std::string name );
std::string string_to_lowercase( std::string string );

template <typename T, typename U>
void delete_map( std::map<T, U> & map )
{
	typename std::map<T, U>::iterator it = map.begin();
	for ( ; it != map.end(); it++ )
	{
		delete ( it->second );
	}
	map.clear();
}

template<typename T>
bool is_in_array( T value, T array[], unsigned int size_array )
{
	for ( unsigned int i = 0; i < size_array; i++ )
	{
		if ( value == array[i] )
		{
			return ( true );
		}
	}
	return ( false );
}

template<typename T>
unsigned int get_array_index( T value, T array[], unsigned int size_array )
{
	for ( unsigned int i = 0; i < size_array; i++ )
	{
		if ( value == array[i] )
		{
			return ( i );
		}
	}
	return ( -1 );
}

void examineString( std::string s );
void examineChar( char c );
void examineCharStar( char *cs );

#endif
