#pragma once

#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;

class Connection
{
public:
	Connection();
	void send(std::string authData);

public:
	bool serverConnect = false;
	std::string regDataStr;

private:
	void connectHandler(const boost::system::error_code& err);

private:
	io_service service;
	std::unique_ptr<ip::tcp::socket> serverSock;
	std::unique_ptr<ip::tcp::endpoint> ep;

	const uint16_t SERV_PORT = 5555;

};