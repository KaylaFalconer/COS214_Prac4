using namespace std;

#include "Decorator.h"
#include "Vet.h"

Decorator::Decorator(Vet* patient) {
}

void Decorator::print() const {
	throw "Not yet implemented";
}

bool Decorator::hasEmergencyPriority() const {
	throw "Not yet implemented";
}


