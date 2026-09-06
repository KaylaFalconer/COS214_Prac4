#include <iostream>
using namespace std;

#include "Decorator.h"
#include "Vet.h"

Decorator::Decorator(Vet* patient) : Vet(patient->getName()) {
	this->patient = patient;
}

bool Decorator::hasEmergencyPriority() const {
	return this->patient->hasEmergencyPriority();
}

Decorator::~Decorator() {
	delete this->patient;
}