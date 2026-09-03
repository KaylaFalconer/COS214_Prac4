#ifndef EMERGENCYPRIORITYITERATOR_H
#define EMERGENCYPRIORITYITERATOR_H

#include <vector>
using namespace std;

#include "Iterator.h"

class Vet;
class Unit;

class EmergencyPriorityIterator: public Iterator
{
	private:
		vector<Vet*> _patients;
		size_t _currentPatient;

		void getEmergencyPatients(Vet* vet);

	public:
		EmergencyPriorityIterator(Unit* root);

		Vet* next() override;
		bool hasNext() const override;
};

#endif
