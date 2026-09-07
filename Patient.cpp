#include <string>
#include <iostream>
using namespace std;

#include "Patient.h"
#include "VetSystem.h"
#include "State.h"
#include "Vet.h"
#include "Admitted.h"

Patient::Patient(const string& id, const string& name, const string& type, int age) :Vet(name), id(id), type(type), age(age) {
	this->state=new Admitted();
}

void Patient::print() const {
	if(state == nullptr) {
		cout << "Patient " << name << " has no state assigned." << endl;
		return;
	}
	std::cout<<"Patient Name: "<<name<<" (ID: "<<id<<", Type: "<<type<<", Age: "<<age<<")\n"<<"Current state: "<<state->getStateName()<<endl;
}

void Patient::advance() {
	if(state != nullptr) {
		state->handle(this);
	}
}

void Patient::setState(State* state) {
	if(state!=nullptr){
		delete this->state;
	}
	this->state = state;
	if(state != nullptr) {
		cout<<"Patient "<<name<<" state changed to "<<state->getStateName()<<endl;
	} else {
		cout<<"Patient "<<name<<" state has been set to nullptr."<<endl;
	}
}

std::string Patient::getStateName() const {
	return this->state->getStateName();
}

bool Patient::hasEmergencyPriority() const {
	return false;
}

Patient::~Patient() {
	if(state != nullptr) {
		delete state;
	}
}

void Patient::readmit() {
	if(getStateName() == "Discharged") {
		setState(new Admitted());
		cout<<"Patient "<<name<<" has been readmitted."<<endl;
	} else {
		cout<<"Patient "<<name<<" cannot be readmitted as they are not discharged."<<endl;
	}
}

string Patient::getName() const {
	return name;
}

string Patient::getId() const {
	return id;
}
