#include <string>
using namespace std;

#include "InTreatment.h"
#include "Patient.h"
#include "State.h"
#include "Discharged.h"

InTreatment::InTreatment() : State("In Treatment") {}

InTreatment::~InTreatment() {}

void InTreatment::handle(Patient* patient) {
	patient->setState(new Discharged());
}

std::string InTreatment::getStateName() const {
	return "In Treatment";
}

