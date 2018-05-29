#include "client.h"

using namespace std;

string prepareMessage(const char * parser);

int main(void)
{
	const char * parser = "news.mit.edu/rss/topic/biological-engineering-and-biotechnology ";
	const char * port = "80";
	client c;
	c.setParser(parser);
	c.setPort(port);
	c.prepareMessage(parser);
	c.connect(c.Gethost().c_str(), c.getPort().c_str());
//	c.sendMessage(c.getMessage().c_str());
	c.sendMessage();
	c.receiveMessage();
	//string final= prepareMessage(test.c_str());
	
	
	//char get[] = "GET /rss/research HTTP/1.1\n";
	//char get2[] = "Host: news.mit.edu\n";
	//char get3 = 0x0A0D;
	//std::string test = "GET /rss/topic/biological-engineering-and-biotechnology HTTP/1.1\n";
	//std::string test1 = "Host: news.mit.edu\n";
	//std::string test3 = "\n";
	//std::string final = test + test1 + test3;
	//c.connect("news.mit.edu", "80");
	//c.sendMessage(final.c_str());
	//c.receiveMessage();
	
	getchar();
	return 0;
}



string prepareMessage(const char * parser)
{
	string firstp = "";
	string secondp = "";
	stringstream aux(parser);
	getline(aux, firstp, '/');
	getline(aux, secondp);

	secondp = "GET /" + secondp + " HTTP/1.1\n";				//le pongo la barra ahi despuesdel get pq se borra cuando haces el getline
	firstp = "Host: " + firstp + "\n";
	
	string Final = secondp + firstp + "\n";

	return Final;
}