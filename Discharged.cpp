#include <string>
using namespace std;
#include <iostream>
#include "Discharged.h"
#include "Patient.h"
#include "State.h"

Discharged::Discharged() : State("Discharged") {}	

void Discharged::handle(Patient* patient) {
	std::cout<<"Patient "<<patient->getName()<<" (ID: "<<patient->getId()<<") has been discharged."<<std::endl;
}
std::string Discharged::getStateName() const {
	return "Discharged";
}

Discharged::~Discharged() {}
