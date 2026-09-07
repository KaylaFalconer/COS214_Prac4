#include <string>
#include <iostream>
using namespace std;

#include "Isolation.h"
#include "Vet.h"
#include "Decorator.h"

Isolation::Isolation(Vet* patient, const string& reason) : Decorator(patient) {
	this->reason = reason;
}

void Isolation::print() const {
	this->patient->print();
	cout << "Isolation Reason: -- " << this->reason << " --" << endl;
}
