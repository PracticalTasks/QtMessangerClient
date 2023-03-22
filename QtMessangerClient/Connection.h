#pragma once

#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;

class Connection
{
public:
	Connection();

private:
	void connectHandler(const boost::system::error_code& err);

private:
	io_service service;
	std::unique_ptr<ip::tcp::socket> serverSock;
	std::unique_ptr<ip::tcp::endpoint> ep;
	std::string userName = "Ivan";
	std::string userPassword = "12345";

	const uint16_t SERV_PORT = 5555;

};