#include <string>
using namespace std;

#include "UnderExamination.h"
#include "Patient.h"
#include "State.h"
#include "InTreatment.h"


UnderExamination::UnderExamination() : State("Under Examination") {}

void UnderExamination::handle(Patient* patient) {
	patient->setState(new InTreatment());
}

std::string UnderExamination::getStateName() const {
	return "Under Examination";
}

UnderExamination::~UnderExamination() {}

