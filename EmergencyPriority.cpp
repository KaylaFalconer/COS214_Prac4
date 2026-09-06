#include <iostream>
using namespace std;

#include "EmergencyPriority.h"
#include "Vet.h"
#include "Decorator.h"

EmergencyPriority::EmergencyPriority(Vet* patient, int level) : Decorator(patient) {
	this->priorityLevel = level;
}

bool EmergencyPriority::hasEmergencyPriority() const {
	return this->priorityLevel > 0;
}

void EmergencyPriority::print() const {
	this->patient->print();
	cout << "Emergency Priority Level: -- " << this->priorityLevel << " --" << endl;
}
