#ifndef UNIT_H
#define UNIT_H

#include <string>
#include <vector>
using namespace std;

#include "Vet.h"

class Iterator;

class Unit: public Vet
{
	friend class FullIterator;
	friend class EmergencyPriorityIterator;
	protected:
		vector<Vet*> children;

	public:
		Unit(const string& name);

		void add(Vet* vet);
		void remove(Vet* vet);

		void print() const override;

		Iterator* createFullIterator();
		Iterator* createEmergencyPriorityIterator();

		bool hasEmergencyPriority() const override;

		virtual ~Unit();
};

#endif
