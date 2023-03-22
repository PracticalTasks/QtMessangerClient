#include "Connection.h"

Connection::Connection()
{
	serverSock = std::make_unique<ip::tcp::socket>(service);
	ep = std::make_unique<ip::tcp::endpoint>(ip::address::from_string("127.0.0.1"), SERV_PORT);
	
	serverSock->async_connect(*ep.get(), boost::bind(&Connection::connectHandler, this, placeholders::error));
	service.run();

}

void Connection::connectHandler(const boost::system::error_code& err)
{
	if (!err)
	{
		std::cout << "Connect is successful!\n";

		write(*serverSock.get(), buffer(userName + '@' + userPassword));
	}
}
