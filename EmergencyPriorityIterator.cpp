#include <vector>
using namespace std;

#include "EmergencyPriorityIterator.h"
#include "Vet.h"
#include "Unit.h"
#include "Iterator.h"

EmergencyPriorityIterator::EmergencyPriorityIterator(Unit* root) {
	_patients.clear();
	_currentPatient=0;
	if(root){
		getEmergencyPatients(root);
	}
}

Vet* EmergencyPriorityIterator::next() {
	if (hasNext())
	{
		return _patients[_currentPatient++];
	}
	else
	{
		return nullptr;
	}

}

bool EmergencyPriorityIterator::hasNext() const {
	return _currentPatient < _patients.size();
}

void EmergencyPriorityIterator::getEmergencyPatients(Vet* vet) {
	if(!vet) return;
	Unit *unit=dynamic_cast<Unit*>(vet);
	if(unit){
		for(Vet* child: unit->children){
			getEmergencyPatients(child);
		}
	}
	else{
		if(vet->hasEmergencyPriority()){
			_patients.push_back(vet);
		}
	}
}

