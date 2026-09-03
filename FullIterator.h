#ifndef FULLITERATOR_H
#define FULLITERATOR_H

#include <vector>
using namespace std;

#include "Iterator.h"

class Vet;
class Unit;

class FullIterator: public Iterator
{
	private:
		vector<Vet*> patients;
		size_t currentItem;

		void getPatients(Vet* vet);

	public:
		FullIterator(Unit* root);

		Vet* next() override;
		bool hasNext() const override;
};

#endif
