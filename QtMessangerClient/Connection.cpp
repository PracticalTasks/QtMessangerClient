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

bool Connection::recievResponse()
{
	unsigned char buff[0x1]{};
	boost::system::error_code err_code;
	serverSock->read_some(buffer(buff), err_code);
	
	if (buff[0] == 0xEF)
		return true;

	return false;
}

void Connection::connectHandler(const boost::system::error_code& err)
{
	if (!err)
	{
		serverConnect = true;
		boost::system::error_code err_code;
		char readBuffer[0xFF]{};
		serverSock->read_some(buffer((readBuffer)), err_code);
		userLogin = readBuffer;
	}
}
