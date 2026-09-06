#include "Vet.h"

#include <string>
using namespace std;

Vet::Vet(const string& name) {
	this->name = name;
}

string Vet::getName() const{
	return this->name;
}

