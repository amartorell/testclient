#include "client.h"

int main(void)
{
	client c;
	char get[] = "GET /rss/research HTTP/1.1\n";
	char get2[] = "Host: news.mit.edu\n";
	char get3 = 0x0A0D;
	std::string test = "GET /rss/topic/biological-engineering-and-biotechnology HTTP/1.1\n";
	std::string test1 = "Host: news.mit.edu\n";
	std::string test3 = "\n";
	std::string final = test + test1 + test3;
	std::cout << final;
	c.connect("news.mit.edu", "80");
	c.sendMessage(final.c_str());
	c.receiveMessage();
//	c.receiveMessage();
	getchar();
	return 0;
}