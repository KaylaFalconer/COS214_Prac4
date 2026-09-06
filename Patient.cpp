#include <string>
#include <iostream>
using namespace std;

#include "Patient.h"
#include "VetSystem.h"
#include "State.h"
#include "Vet.h"

Patient::Patient(const string& id, const string& name, const string& type, int age) : Vet(name) {
	this->id = id;
	this->type = type;
	this->age = age;
	this->state = nullptr;
}

void Patient::print() const {
	std::cout << "Patient: -- " << this->getName() << " -- " << this->type << " -- " << this->age << std::endl;
}

void Patient::setState(State* state) {
	if (state)
	{
		this->state = state;
	}
}

void Patient::examine() {
	this->state->examine(*this);
}

void Patient::treat() {
	this->state->treat(*this);
}

void Patient::discharge() {
	this->state->discharge(*this);
}

string Patient::getStateName() const {
	return this->state->getStateName();
}

bool Patient::hasEmergencyPriority() const {
	return false;
}

Patient::~Patient()
{
	delete this->state;
}
