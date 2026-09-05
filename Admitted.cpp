#include <string>
using namespace std;

#include "Admitted.h"
#include "Patient.h"
#include "State.h"
#include "UnderExamination.h"


Admitted::Admitted() : State("Admitted") {}

void Admitted::handle(Patient* patient){
	patient->setState(new UnderExamination());
}

std::string Admitted::getStateName() const{
	return "Admitted";
}

Admitted::~Admitted() {}



