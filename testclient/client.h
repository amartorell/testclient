#pragma once
#include <iostream>
#include <cstdio>
#include <boost/asio.hpp>
#include <boost/chrono.hpp>
#include <boost/timer/timer.hpp>
#include <fstream>
class client
{
public:
	client();
	void connect(const char* host, const char * port);
	void receiveMessage();
	void sendMessage(const char * msg);	//con este mando todo el GET HOST y la linea en blanco que sale si haces "\n"(0d 0a)
	~client();							//pasarle todo ese mensaje como un string concatenado de los 3 agregandole un \n despues de HTTP 1.1 y del Host

private:
	boost::asio::io_service* IO_handler;
	boost::asio::ip::tcp::socket* socket_forClient;
	boost::asio::ip::tcp::resolver* client_resolver;
	boost::asio::ip::tcp::resolver::iterator endpoint;
};

