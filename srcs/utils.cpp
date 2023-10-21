/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:30:30 by cjimenez          #+#    #+#             */
/*   Updated: 2023/10/09 13:43:39 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.hpp"

bool is_in( char c, std::string str )
{
	if ( str.find( c ) != std::string::npos )
	{
		return ( true );
	}
	return ( false );
}

bool is_channel( std::string name )
{
	const std::string channel_types = "#&";
	if ( name.size() <= 0 )
	{
		return ( false );
	}
	if ( is_in( name[0], channel_types ) )
	{
		return ( true );
	}
	return ( false );
}

std::string string_to_lowercase( std::string string )
{
	std::string lowercase = string;
	std::string::iterator it = lowercase.begin();
	for ( ; it != lowercase.end(); it++ )
	{
		*it = std::tolower( *it );
	}
	return ( lowercase );
}
