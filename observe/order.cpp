#include"header.h"
#include"command.h"

void Broker::takeorder(Order* order){
	orderlist.push_back(order);
}

void Broker::placeorder() {
	for (auto i : orderlist)
	{
		i->execute();
	}
}

void Broker::clear() {
	orderlist.clear();
}

void KMakeOrder::execute() {
	kind->make();
}

void PMakeOrder::execute() {
	packedge->make();
}