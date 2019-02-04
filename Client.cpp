#define WIN32_LEAN_AND_MEAN

#include <vector>
#include "pugixml.hpp"

#include "ClientConnection.hpp"

using namespace ClientLayer;
int __cdecl main(int argc, char **argv)
{
	pugi::xml_document config_file;
	pugi::xml_parse_result result = config_file.load_file("client_message.xml");
	if (result.status != pugi::xml_parse_status::status_ok)
	{
		//can't find file;
	}

	auto client = config_file.child("client");
	std::string ID = client.attribute("id").value();
	std::string IP = client.attribute("server_ip").value();
	int interval = client.attribute("interval").as_int();

	auto itemsCollection = config_file.child("client").child("items");
	auto items = ClientLayer::getItems(itemsCollection);

	ClientLayer::send_message(ID, IP, interval, items);

	return 0;
}