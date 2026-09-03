#ifndef UNIT_H
#define UNIT_H

#include <string>
#include <vector>
using namespace std;

#include "Vet.h"

class Iterator;

class Unit: public Vet
{
	protected:
		vector<Vet*> children;

	public:
		Unit(const string& name);

		void add(Vet* vet);
		void remove(Vet* vet);

		void print() const override;

		Iterator* createIterator();
		Iterator* createEmergencyPriorityIterator();

		bool hasEmergencyPriority() const override;

		virtual ~Unit();
};

#endif
