#include <string>
using namespace std;
#include <iostream>	
#include "Patient.h"
#include "VetSystem.h"
#include "State.h"
#include "Vet.h"
#include "Admitted.h"

Patient::Patient(const string& id, const string& name, const string& type, int age) :id(id), type(type), age(age), Vet(name) {
	this->state=new Admitted();
}

void Patient::print() const {
	std::cout<<"Patient Name: "<<name<<" (ID: "<<id<<", Type: "<<type<<",Age: "<<age<<")\n"<<"Current state: "<<state->getStateName()<<std::endl;
}

void Patient::setState(State* state) {
	if(state!=nullptr){
		delete this->state;
	}
	this->state = state;
	cout<<"Patient "<<name<<" state changed to "<<state->getStateName()<<std::endl;
}

void Patient::advance() {
	state->handle(this);
}

void Patient::readmit() {
	if(getStateName() == "Discharged") {
		setState(new Admitted());
		cout<<"Patient "<<name<<" has been readmitted."<<std::endl;
	} else {
		cout<<"Patient "<<name<<" cannot be readmitted as they are not discharged."<<std::endl;
	}
}

string Patient::getStateName() const {
	return state->getStateName();
}

string Patient::getName() const {
	return name;
}

string Patient::getId() const {
	return id;
}


bool Patient::hasEmergencyPriority() const {
		
}

Patient::~Patient() {
	if(state != nullptr) {
		delete state;
	}
}


