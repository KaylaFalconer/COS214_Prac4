#include <vector>
using namespace std;

#include "FullIterator.h"
#include "Vet.h"
#include "Unit.h"
#include "Iterator.h"

FullIterator::FullIterator(Unit* root) {
	patients.clear();
	currentItem=0;
	if(root){
		getPatients(root);
	}
}

Vet* FullIterator::next() {
	if (hasNext())
	{
		return patients[currentItem++];
	}
	else
	{
		return nullptr;
	}
}

bool FullIterator::hasNext() const {
	return currentItem < patients.size();
}

void FullIterator::getPatients(Vet* vet) {
	if(!vet) return;
	Unit *unit=dynamic_cast<Unit*>(vet);
	if(unit){
		for(Vet* child: unit->children){
			getPatients(child);
		}
	}
	else{
		patients.push_back(vet);
	}
}

