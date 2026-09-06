using namespace std;

#include "VetSystem.h"
#include "Unit.h"
#include "Vet.h"
#include "Iterator.h"
#include "Patient.h"
#include "FullIterator.h"
#include "EmergencyPriorityIterator.h"

VetSystem::VetSystem(Unit *root)
{
	this->root = root;
}

void VetSystem::printAll() const
{
	if (this->root)
	{
		this->root->print();
	}
}

void VetSystem::showAllPatients()
{
	Iterator* full = new FullIterator(this->root);
	while (full->hasNext())
	{
		Vet* current = full->next();
		if (current)
		{
			current->print();
		}
	}
	delete full;
}

void VetSystem::showEmergencyPriorityPatients()
{
	Iterator* emergency = new EmergencyPriorityIterator(this->root);
	while (emergency->hasNext())
	{
		Vet* current = emergency->next();
		if (current)
		{
			current->print();
		}
	}
	delete emergency;
}

void VetSystem::processPatient(Patient* patient)
{
	if (patient)
	{
		patient->advance();
		patient->advance();
		patient->advance();
	}
}

VetSystem::~VetSystem()
{
	delete this->root;
}
