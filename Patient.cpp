#include <string>
using namespace std;

#include "Patient.h"
#include "VetSystem.h"
#include "State.h"
#include "Vet.h"

Patient::Patient(const string& id, const string& name, const string& type, int age) {
}

void Patient::print() const {
	throw "Not yet implemented";
}

void Patient::setState(State* state) {
	throw "Not yet implemented";
}

void Patient::examine() {
	throw "Not yet implemented";
}

void Patient::treat() {
	throw "Not yet implemented";
}

void Patient::discharge() {
	throw "Not yet implemented";
}

string Patient::getStateName() const {
	throw "Not yet implemented";
}

bool Patient::hasEmergencyPriority() const {
	throw "Not yet implemented";
}


