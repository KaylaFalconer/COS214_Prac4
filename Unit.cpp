#include "Unit.h"
#include "Vet.h"
#include "Iterator.h"
#include "FullIterator.h"
#include "EmergencyPriorityIterator.h"

#include <string>
#include <vector>
#include <iostream>
using namespace std;

Unit::Unit(const string &name) : Vet(name) {}

bool Unit::hasEmergencyPriority() const
{
	throw "Not yet implemented";
}

void Unit::add(Vet* vet)
{
	this->children.push_back(vet);
}

void Unit::remove(Vet* vet)
{
	//
}

void Unit::print() const
{
	std::cout << "Unit: -- " << this->getName() << " -- " << std::endl;
	for (Vet* child : this->children)
	{
		if (child)
		{
			child->print();
		}
	}
}

Iterator* Unit::createFullIterator()
{
	return new FullIterator(nullptr);
}

Iterator* Unit::createEmergencyPriorityIterator()
{
	return new EmergencyPriorityIterator(nullptr);
}