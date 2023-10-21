#ifndef PASSWORD_H
#define PASSWORD_H

#include "ft_irc.hpp"


/* DEFAULT_CONNECTION_PASSWORD my ceo "kameto" in sha256 */
#define DEFAULT_CONNECTION_PASSWORD "165b23d14aa1ba76b90ef3d7e96a529f49012c00c38ba275d8e06dc20a476849"

class Password
{
	private:
		std::string connection_password_hash;
		std::string create_sha256_hash(std::string plain_text);
		
	public:
	Password(std::string connection_password);
	virtual ~Password();

	std::string get_hash(std::string plain_text);
	void validate_connection_password(std::string password);
	void validate_password(std::string hash, std::string password);

	class InvalidPasswordException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif
