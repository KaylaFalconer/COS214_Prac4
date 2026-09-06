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
	for (Vet* child : this->children) {
		if (child)
		{
			if (child->hasEmergencyPriority()) return true;
		}
	}
	return false;
}

void Unit::add(Vet* vet)
{
	this->children.push_back(vet);
}

void Unit::remove(Vet* vet)
{
	for (auto it = this->children.begin(); it != this->children.end(); ) {
		if (*it == vet)
		{
			it = this->children.erase(it);
		}
		else
		{
			++it;
		}
		
	}
}

void Unit::print() const
{
	std::cout << "Unit: -- " << this->getName() << " --" << std::endl;
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
	return new FullIterator(this);
}

Iterator* Unit::createEmergencyPriorityIterator()
{
	return new EmergencyPriorityIterator(this);
}

Unit::~Unit()
{
	for (Vet* child : this->children) {
		delete child;
		child = nullptr;
	}
	this->children.clear();
}
