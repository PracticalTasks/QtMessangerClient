#include "Connection.h"

Connection::Connection()
{
	serverSock = std::make_unique<ip::tcp::socket>(service);
	ep = std::make_unique<ip::tcp::endpoint>(ip::address::from_string("127.0.0.1"), SERV_PORT);
	
	serverSock->async_connect(*ep.get(), boost::bind(&Connection::connectHandler, this, placeholders::error));
	service.run();

}

void Connection::send(std::string authData)
{
	write(*serverSock.get(), buffer(authData));
}

void Connection::connectHandler(const boost::system::error_code& err)
{
	if (!err)
	{
		serverConnect = true;
		boost::system::error_code err_code;
		char readBuffer[0xFF]{ 0 };
		serverSock->read_some(buffer(readBuffer), err_code);
		regDataStr = readBuffer;
	}
}
