#pragma once
#include "string"
#include <math.h>

namespace ClientLayer {
	struct itemData
	{
		std::string name;
		std::string value;

		itemData()
		{
			name = "";
			value = "";
		}
		bool operator== (const itemData& rhs) const
		{
			return this->name == rhs.name;
		}
	};

	std::vector<itemData> getItems(pugi::xml_node itemsCollection)
	{
		std::vector<itemData> items;
		auto item = itemsCollection.child("item");

		for (item; item != pugi::xml_node(); item = item.next_sibling())
		{
			itemData temp;
			temp.name = item.attribute("name").value();
			temp.value = item.attribute("value").value();

			items.push_back(temp);
		}
		return items;
	}

	void addItems(std::string& string, std::vector<itemData> items)
	{
		for (auto item : items)
		{
			item.value = std::to_string(rand() % 10);
			string += "<item name = \"" + item.name + "\" value=\"" + item.value + "\"/>";
		}
		string += "</client>";
	}
}